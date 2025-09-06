const fs = require('fs')

filepath = process.argv[2]
if (filepath === undefined) {
  console.log("no filepath provided")
  return
}

fs.readFile(filepath, 'utf8', (err, data) => {
  if (err) {
    console.log('Error reading the file:', err);
  } else {
    console.log(data.split('\n').length - 1);
  }
})
