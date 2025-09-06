const http = require('http');
const url = process.argv[2];

http.get(url, (response) => {
  if (response.statusCode !== 200) {
    console.error(`HTTP error! Status: ${response.statusCode}`);
    return;
  }
  response.setEncoding('utf8');
  response.on('data', (chunk) => {
    console.log(chunk)
  });
}).on('error', (err) => {
  console.error(`Error: ${err.message}`);
});
