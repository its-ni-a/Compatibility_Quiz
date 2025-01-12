import pandas as pd

# Data for the quiz questions
data = {
    "id": [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20],
    "question": [
        "Do you love Jehovah?",
        "Are you baptized?",
        "Are you a ministerial servant?",
        "How many years have you been baptized?",
        "Do you know a trade? (i.e. electrical, HVAC, plumbing, welding, carpentry)",
        "Do you have a salary job?",
        "If you don't have a salary job are you in Bethel?"
        #"When at a party are you: ",
        #"Are you an introvert or extrovert?",
        #"Do you like to travel?",
        #"Do you like to try new things?",
        #"If you don't live in New York, would you be willing to move to here?",
        #"Do you have a car?",
        #"If you have a car, do you know how to change a tire?",
        #"Do you watch red pill podcasts?",
        #"Have you been married before?",
        #"Do you have a girl best friend?",
        #"Does anyone think you are in a relationship with them?"
    ],
    "options": [
        ["Absolutely", "Sure", "Kind of", "No"], # end if no
        ["Yes", "No"], # end if no
        ["Yes", "No"], # end if no
        ["Yes", "No"],
        ["10+ years", "5-10 years", "2-5 years", "Less than 2 years"], 
        ["Yes", "No"],
        ["Yes", "No"],
        #["The life of the party", "I'm on the dance floor", "I'm at the snack table", "I'm not even at the party"],
        #["introvert", "a good mix of both", "extrovert"],
        #["Absolutely", "Sometimes", "Not really", "No"],
        #["Absolutely", "Sometimes", "Not really", "No"],
        #["Absolutely", "It depends", "Not really", "No"],
        #["Yes", "No"],
        #["Yes", "No"],
        #["Yes", "Sometimes", "Not really", "No"],
        #["Yes", "No"],
        #["Yes", "Kind of", "No"],
        #["Yes", "Maybe", "Not really", "No"],
    ],
    "scores": [
        [10, 0, 0, 0],
        [10, 0],
        [10, 0],
        [10, 9, 5, 3],
        [10, 5],
        [10, 0],
        [10, 0],
        #[6, 8, 10, 4],
        #[5, 10, 5],
        #[10, 7, 3, 0],
        #[10, 7, 3, 0],
        #[10, 7, 3, 0],
        #[10, 0],
        #[10, 0],
        #[0, 0, 0, 10],
        #[10, 0],
        #[0, 0, 10],
        #[0, 0, 5, 10],
    ]
}

# Create a DataFrame from the data
df = pd.DataFrame(data)

# Specify the filename for the Excel file
filename = './excel/questions.xlsx'

# Save the DataFrame to an Excel file
df.to_excel(filename, index=False)

print(f"Quiz questions saved to {filename}")
