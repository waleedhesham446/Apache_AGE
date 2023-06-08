import psycopg2
import json
from decimal import Decimal

class DecimalEncoder(json.JSONEncoder):
    def default(self, o):
        if isinstance(o, Decimal):
            return int(o)
        return super().default(o)

# Connect to the PostgreSQL database
conn = psycopg2.connect(
    host="your_host",
    database="your_database",
    user="your_user",
    password="your_password"
)

# Create a cursor object to execute SQL queries
cur = conn.cursor()

# Execute a SELECT query to retrieve data from the table
cur.execute("SELECT * FROM public.user_table")

# Fetch all rows returned by the query
rows = cur.fetchall()

# Define a list to store the rows as dictionaries
result = []

# Convert each row to a dictionary and append to the result list
for row in rows:
    user = {
        "user_id": row[0],
        "name": row[1],
        "age": row[2]
    }
    if row[3] is not None:
        user["phone"] = row[3]

    result.append(user)

# Create the final JSON object
json_output = {
    "status_code": 200,
    "data": result
}

# Convert the JSON object to a string
json_string = json.dumps(json_output, cls=DecimalEncoder)

# Print the JSON string
print(json_string)

# Close the cursor and connection
cur.close()
conn.close()
