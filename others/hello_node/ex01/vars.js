function printWithType(variable) {
  let var_type = typeof(variable)
  console.log(`${variable} is ${var_type == "object" || var_type == "undefined" ? "an" : "a"} ${var_type}`)
}

printWithType(42)
printWithType("42")

obj_ft = Object(42)
printWithType(obj_ft)

printWithType(true)
printWithType(undefined)

// console.log(typeof())