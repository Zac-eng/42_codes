const args = process.argv
const argc = args.length

let args_array = []

for (let i = 2; i < argc; ++i) {
  let arg_int = parseInt(args[i])
  if (arg_int === NaN) {
    console.log("invalid argument included")
    return
  }
  args_array.push(arg_int)
}

console.log(args_array.reduce((acc, num) => acc + num, 0))
