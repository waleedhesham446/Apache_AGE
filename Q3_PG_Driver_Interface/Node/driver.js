// Import the required libraries
const { Pool } = require('pg');

// Create a function to fetch data from the user_table in JSON format
async function fetchUserData() {
  // Create a new instance of the Pool class with your PostgreSQL connection details
  const pool = new Pool({
    user: 'your_user',
    host: 'your_host',
    database: 'your_database',
    password: 'your_password',
    port: 'your_port',
  });

  // Connect to the PostgreSQL database
  const client = await pool.connect();

  try {
    // Execute the SQL query to fetch user data from the user_table
    const query = 'SELECT user_id, name, age, phone FROM public.user_table ORDER BY user_id ASC';
    const result = await client.query(query);

    // Remove null values from the result rows
    const filteredRows = result.rows.map(row => {
      const filteredRow = {};
      for (const key in row) {
        if (row[key] !== null) {
          filteredRow[key] = row[key];
        }
      }
      return filteredRow;
    });

    // Format the query result as a JSON string
    const jsonData = JSON.stringify({
      status_code: 200,
      data: filteredRows,
    });

    // Return the JSON string
    return jsonData;
  } finally {
    // Release the client and the connection pool
    client.release();
    pool.end();
  }
}

// Call the fetchUserData function and log the result
fetchUserData()
  .then((jsonData) => console.log(jsonData))
  .catch((error) => console.error('Error:', error));
