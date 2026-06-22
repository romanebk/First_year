import streamlit as st
import pandas as pd
import joblib
from sklearn.preprocessing import LabelEncoder

df = pd.read_csv("cleaned_dataset.csv")
model = joblib.load("model_classification.pkl")
model_reg = joblib.load("model_regression.pkl")

service_options = df["Service"].unique()
departure_options = df["Departure station"].unique()
arrival_options = df["Arrival station"].unique()

min_month = df["Month"].min()
max_month = df["Month"].max()
#min_day = df["Day of Week"].min()
#max_day = df["Day of Week"].max()
min_trains = df["Number of scheduled trains"].min()
max_trains = df["Number of scheduled trains"].max()
min_cancelled = df["Number of cancelled trains"].min()
max_cancelled = df["Number of cancelled trains"].max()
min_time = df["Average journey time"].min()
max_time = df["Average journey time"].max()
day_map = {
    "Monday": 0, "Tuesday": 1, "Wednesday": 2,
    "Thursday": 3, "Friday": 4, "Saturday": 5, "Sunday": 6
}
delay_cat_options = df["delay_category"].unique()

st.title("Prédiction de Retard de Train")
service = st.selectbox("Type de service", service_options)
departure = st.selectbox("Gare de départ", departure_options)
arrival = st.selectbox("Gare d'arrivée", arrival_options)
month = st.slider("Mois", int(min_month), int(max_month), int(min_month))
day_name = st.selectbox("Jour de la semaine", list(day_map.keys()))
day = day_map[day_name]
weekend = st.radio("Est-ce un week-end ?", [0, 1])
scheduled = st.slider("Nombre de trains programmés", int(min_trains), int(max_trains), int(min_trains))
cancelled = st.slider("Nombre de trains annulés", int(min_cancelled), int(max_cancelled), int(min_cancelled))
duration = st.slider("Durée moyenne du trajet (min)", int(min_time), int(max_time), int(min_time))
delay_category = st.selectbox("Catégorie de retard", delay_cat_options)


input_df = pd.DataFrame([{
    "Service": service,
    "Departure station": departure,
    "Arrival station": arrival,
    "Month": month,
    "Day of Week": day,
    "is_weekend": weekend,
    "Number of scheduled trains": scheduled,
    "Number of cancelled trains": cancelled,
    "Average journey time": duration
}])

input_reg = pd.DataFrame([{
    "Service": service,
    "Departure station": departure,
    "Arrival station": arrival,
    "Month": month,
    "Day of Week": day,
    "Number of scheduled trains": scheduled,
    "Average journey time": duration,
    "delay_category": delay_category,
    "is_weekend": weekend
}])

#encoder = LabelEncoder()
""" for col in ["Service", "Departure station", "Arrival station"]:
    input_df[col] = encoder.fit_transform(input_df[col])

for col in ["Service", "Departure station", "Arrival station", "delay_category"]:
    input_reg[col] = encoder.fit_transform(input_reg[col])
 """
for col in ["Service", "Departure station", "Arrival station"]:
    encoder = LabelEncoder()
    input_df[col] = encoder.fit_transform(input_df[col])

for col in ["Service", "Departure station", "Arrival station", "delay_category"]:
    encoder = LabelEncoder()
    input_reg[col] = encoder.fit_transform(input_reg[col])

if st.button("Prédire le retard"):
    prediction = model.predict(input_df)[0]
    if prediction == 1:
        st.error("Le train sera probablement en retard.")
    else:
        st.success("Le train devrait être à l'heure.")

st.subheader("Combien de minutes de retard ?")
if st.button("Estimer le temps de retard (régression)"):
    pred_delay = model_reg.predict(input_reg)[0]
    st.info(f"⏱️ Retard estimé : {round(pred_delay, 2)} minutes")
