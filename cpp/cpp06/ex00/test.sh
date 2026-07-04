make re
./convert 0
./convert 0.0
./convert 0.0f
./convert a
./convert 42
./convert 42.1
./convert 42.01f
./convert inf
./convert +inf
./convert -inf
./convert inff
./convert +inff
./convert -inff
./convert nan
./convert nanf
./convert $(expr $(getconf INT_MAX))
./convert $(expr $(getconf INT_MIN))
./convert $(expr $(getconf INT_MAX) + 1)
./convert $(expr $(getconf INT_MIN) - 1)

