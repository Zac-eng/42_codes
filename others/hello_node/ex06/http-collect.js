// const http = require("http")
// const url = process.argv[2]

const http = require('http');
const bl = require('bl');
const url = process.argv[2]

// Send a GET request to a URL
http.get(url, (response) => {
  // Use the 'bl' module to collect the response data
  response.pipe(bl((err, data) => {
    if (err) {
      console.error('Error:', err);
      return;
    }

    // The data is now accumulated into a single Buffer
    console.log('Received data:');
    console.log(data.toString()); // Convert the Buffer to a string and log it
  }));
});


