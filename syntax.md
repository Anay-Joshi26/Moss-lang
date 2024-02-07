# Moss Programming language syntax

Moss is a strongly typed toy programming language. It supports:
- Variables
- Arithmetic operations
- Loops
- If/Else statements

## Syntax

#### General Syntax
Its syntax is as follows:

To declare a variable

```
a = 3;
```

Alternatively, a variable can be given a type

```
int a = 3;
```

By default variables can be re-assigned, e.g this is valid within Moss

```
int a = 3;
a = 6;
print(a) // will print 6
```

Variables written in all caps will be constant variables which do not support re-assignment. With constant variables a type cannot be provided

```

PI = 3.14;
PI = 3; // will cause an error
```

The same can be achieved with the `const` keyword

```
const pi = 3.14;
pi = 3; // will cause an error
```

We recommend all constant variables to be kept as capital variables.

#### While Loops

While loops have the following syntax:

```
while (condition) {
    // some code
}
```
The syntax is the same as most programming languages such as Java or Javascript

### For loops

```
for () {

}

```



