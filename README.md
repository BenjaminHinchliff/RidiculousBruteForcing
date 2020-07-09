# RidiculousBruteForcing

## About
A program to determine the correct unary and binary operations between 3, 7, and 5 to reach a certain number. It's determined via a (slightly spagetti) recursive backtracking function.

## Usage

### Format

#### Windows:
```bat
RidiculousBruteForcing.exe [min] [max (inclusive)]
```
#### Linux/Mac:
```bash
./RidiculousBruteForcing [min] [max (inclusive)]
```

### Example

#### Windows:
```bat
RidiculousBruteForcing.exe 1 100
```

#### Linux/Mac:
```bash
./RidiculousBruteForcing 1 100
```

#### Output:
```
3 + 7 ** 5! = 0
3 + (-7) + 5 = 1
3 + 7 / 5 = 2
(-3^2) + 7 + 5 = 3
3 * (-7) + 5^2 = 4
3 + 7 + (-5) = 5
3! * 7^2^2 - 5!^2 = 6
3^2 + (-7) + 5 = 7
3! + 7 + (-5) = 8
(-3) + 7 + 5 = 9
3^2 + (-7) * 5 = 10
3! + 7^2 / 5 = 11
3!^2 + (-7^2) + 5^2 = 12
3 + 7 + 5 = 15
3 * 7 + (-5) = 16
3! * 7 + (-5^2) = 17
3! + 7 + 5 = 18
3 + (-7) * (-5) = 20
3 + (-7) + 5^2 = 21
(-3^2) + 7 + 5^2 = 23
3! + (-7) + 5^2 = 24
3! + (-7) * (-5^2) = 25
3 * 7 + 5 = 26
3 + 7^2 + (-5^2) = 27
(-3) + 7 + 5^2 = 29
3! + 7^2 + (-5^2) = 30
3^2 + (-7) ** 5 = 32
3^2 + 7^2 + (-5^2) = 33
3!^2 + (-7) + 5 = 34
3 + 7 + 5^2 = 35
3!! + (-7!) / (-5!) = 36
3! * 7 + (-5) = 37
3! + 7 + 5^2 = 38
3^2 + 7 + 5^2 = 41
3!! * 7 / 5! = 42
(-3^2) + 7^2 + 5 = 45
3 * 7 + 5^2 = 46
3 + 7^2 + (-5) = 47
3!! + 7! / 5! = 48
3^2^2 + (-7) + (-5^2) = 49
3 + 7 * 5 = 50
(-3) + 7^2 + 5 = 51
3^2 + 7^2 + (-5) = 53
3!^2 + (-7) + 5^2 = 54
3 + 7^2 + 5 = 57
3^2 * 7 + (-5) = 58
3! + 7^2 + 5 = 60
(-3^2) + (-7^2) + 5! = 62
3^2 + 7^2 + 5 = 63
3! + 7 * 5 = 65
3! * 7 + 5^2 = 67
3^2 * 7 + 5 = 68
3^2^2 + (-7) + (-5) = 69
(-3) + 7^2 + 5^2 = 71
3 + (-7^2) + 5! = 74
3 + 7^2 + 5^2 = 77
3! * (-7) + 5! = 78
3^2^2 + (-7) + 5 = 79
3! + 7^2 + 5^2 = 80
3^2 + 7^2 + 5^2 = 83
3^2 * 7 + 5^2 = 88
3!^2 + 7^2 + 5 = 90
3^2^2 + 7 + 5 = 93
3^2! / 7! + 5^2 = 97
3 * (-7) + 5! = 99
3 + (-7) * (-5^2) = 100
```

## Compilation

standard cmake compilation with at least C++11 support
