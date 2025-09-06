const fs = require('fs')

filepath = process.argv[2]
if (filepath === undefined) {
  console.log("no filepath provided")
  return
}

let data = fs.readFileSync(filepath, "utf-8")
console.log(data.split('\n').length - 1)
