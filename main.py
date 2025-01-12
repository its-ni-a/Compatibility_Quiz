import os
import pandas as pd
from flask import Flask, request, jsonify

app = Flask(__name__)

# Global variable to store user scores
user_scores = []

# Load existing scores from Excel if the file exists
def load_scores_from_excel():
    if os.path.exists('scores.xlsx'):
        df = pd.read_excel('scores.xlsx')
        for _, row in df.iterrows():
            user_scores.append({"username": row['username'], "score": row['score']})

# Load questions from an Excel file
def load_questions():
    df = pd.read_excel('questions.xlsx', sheet_name='questions')
    questions = []
    for _, row in df.iterrows():
        question = {
            "id": row['id'],
            "question": row['question'],
            "options": row['options'].split(', '),  # Ensure options are comma-separated
            "scores": list(map(int, row['scores'].split(','))),  # Convert scores to integers
            "terminate": row.get('terminate', False)  # Ensure this column exists or default to False
        }
        questions.append(question)
    return questions

# Load questions when the application starts
questions = load_questions()
load_scores_from_excel()

@app.route('/question/<int:question_id>', methods=['GET'])
def get_question(question_id):
    """Fetch a question by its ID."""
    question = next((q for q in questions if q["id"] == question_id), None)
    if question is None:
        return jsonify({"error": "Question not found"}), 404
    return jsonify({"question": question})

@app.route('/question/<int:question_id>', methods=['POST'])
def handle_answer(question_id):
    """Handle user's answer to a question."""
    global user_scores

    question = next((q for q in questions if q["id"] == question_id), None)
    if not question:
        return jsonify({"error": "Question not found"}), 404

    user_answer = request.json.get("answer")
    username = request.json.get("username")  # Get username from request

    if user_answer is None or not (0 <= user_answer < len(question["options"])):
        return jsonify({"error": "Invalid answer index"}), 400

    score = question["scores"][user_answer]
    user_scores.append({"username": username, "score": score})

    # Save scores to Excel after each submission
    save_scores_to_excel()

    # Check if we should terminate the quiz
    if question.get("terminate") and user_answer == 1:  # Example termination condition
        return jsonify({
            "message": "I don't even know why you bothered. Goodbye.",
            "score": score,
            "final": True
        })

    next_question_id = question_id + 1
    next_question = next((q for q in questions if q["id"] == next_question_id), None)

    if next_question:
        return jsonify({"question": next_question})
    else:
        return jsonify({"message": "Quiz completed!", "final": True})

@app.route('/save-results', methods=['POST'])
def save_results():
    """Save user responses and scores to an Excel file."""
    data = request.json
    username = data['username']
    user_responses = data['userResponses']
    total_score = data['score']

    # Create a DataFrame to hold the results
    results = []
    for response in user_responses:
        results.append({
            'Username': username,
            'Question': response['question'],
            'Answer': response['answer'],
            'Score': response['score']
        })

    # Convert to DataFrame
    results_df = pd.DataFrame(results)

    # Save to Excel
    if os.path.exists('scores.xlsx'):
        # Append to existing file
        with pd.ExcelWriter('scores.xlsx', mode='a', if_sheet_exists='overlay') as writer:
            results_df.to_excel(writer, sheet_name='Results', index=False, header=False)
    else:
        # Create new file
        results_df.to_excel('scores.xlsx', sheet_name='Results', index=False)

    return jsonify({"message": "Results saved successfully!"})
