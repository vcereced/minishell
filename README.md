<p align="center">
  <a>
    <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/8d/42_Logo.svg/1200px-42_Logo.svg.png" alt="Logo" width="200" height="200">
  </a>

  <p align="center">
    As beautiful as a shell<br>
    Project minishell of 42 school
    <br />
	</p>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Makefile-8A2BE2">
  <img src="https://img.shields.io/badge/C-4682B4">
  <img src="https://img.shields.io/badge/Shell-2E8B57">
  <img src="https://img.shields.io/badge/Gcc-00FF00">
  
</p>

## &#x2728; What is minishell?

This project is about creating a own little shell. Capable of parsing a prompt and launching executables with arguments, along with a few built-in functions like Bash.<br />
It's two-person project was done by `vcereced` and `dgarizad` students of 42..
			
<img width="1010" alt="Screen Shot 2024-03-07 at 12 03 04 PM" src="https://github.com/vcereced/minishell/assets/120835200/b3accf9b-e6ff-447f-8bf8-93baa3402ba3">

     
## 🕹 Features

| | |
|---|---|
|`/bin/ls or ls`| run on absolute, relative or environment PATH.|
|`'  "`|  arguments or options with `'` and `"` work the same as bash. |
|`> >> < \| `| Redirections.|
|`$HOME`| Environment variables. |
|`$?`| return exit status code. |
|`Ctrl-C Ctrl-D`| Handling signals. |
|`&& \|\| `| Decision tree. |
|`*`| Wildcards. |

## 🕹 Built-ins

| | |
|---|---|
|`echo`| `pwd` |
|`cd`|`env`|
|`export`| `unset`|
|`exit`| |


## &#x1F6E0; Algorithm

Schema of global logic without decision tree:

<img width="1083" alt="Screen Shot 2024-03-07 at 12 54 56 PM" src="https://github.com/vcereced/minishell/assets/120835200/0076cd0f-1913-4aa1-a34c-54b25db59522">

Parsing logic:

<img width="400" alt="Screen Shot 2024-03-07 at 12 37 29 PM" src="https://github.com/vcereced/minishell/assets/120835200/fdb78bb0-cb6e-4428-9776-2d240cf6616b">

Planner logic:

<img width="600" alt="Screen Shot 2024-03-07 at 12 43 30 PM" src="https://github.com/vcereced/minishell/assets/120835200/b62fdc1d-f211-43c0-86b7-5a7a82cf0023">

Program logic:

<img width="600" alt="Screen Shot 2024-03-07 at 12 50 09 PM" src="https://github.com/vcereced/minishell/assets/120835200/ba77b088-cf5f-4ad0-9adf-05fbe4215a28">


## &#x1F4BB; Usage

`make` to compile.

`make clean` remove .o files.

`make fclean` remove .o files and .a files and executable.

## &#x1F4D6; Examples

Execute this command in the terminal.

```bash
./minishell
```

Let's try some promps like in a shell:

```bash
echo "hello world" && cat
```

Output should be:
```bash
hello world
```
