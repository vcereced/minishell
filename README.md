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

## &#x1F4CC; Index 
- [📌 Index](#-index)
- [✨ What is minishell?](#-what-is-minishell)
- [🕹 Features](#-features)
- [🕹 Built-ins](#-built-ins)
- [🛠 Algorithm](#-algorithm)
- [💻 Usage](#-usage)
- [📖 Examples](#-examples)

## &#x2728; What is minishell?

This project is about creating a own little shell. Capable of parsing a prompt and launching executables with arguments, along with a few built-in functions.<br />
It's two-person project was done by `vcereced` and `dgarizad` students of 42..
			

      IMAgeng minishel
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

Schema of logic:


<img src="https://github.com/vcereced/push_swap/assets/120835200/8eacd016-1c5c-4ab6-a111-9ebf4c27ce3d" alt="push" width="600">


<br /><br />
Visualization should be:


![Screen-Recording-2024-03-06-at-8 50 31-PM-ezgif com-resize](https://github.com/vcereced/push_swap/assets/120835200/a3e789b9-3a6f-49b6-ac31-58482bc2d87c)


## &#x1F4BB; Usage

`make` to compile.

`exe` to compile and run a example of unsorted numbers.

`make clean` remove .o files.

`make fclean` remove .o files and .a files and executable.

## &#x1F4D6; Examples

Execute this command in the terminal.

```bash
nums="9 8 7 6 5 4" && ./push_swap $nums 
```
Output should be:

```bash
rra
pb
rra
pb
rra
pb
sa
rra
pa
pa
pa
```
