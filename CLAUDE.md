# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this repo is

A personal C++ coursework workspace. Every `.cpp` file is a standalone, single-file console program with its own `main()`; there is no project-wide build system, library code, or test suite. Files are grouped by course and assignment:

- `programming-laboratory/assignment-NN/`, `programming-tasks/assignment-NN/` — course assignments; most files open with a block comment stating the problem.
- `programming-laboratory/group-project/main.cpp` — the one larger program (an event finder using a fixed-size `Event` array, validated input helpers, and sections attributed to group members). Keep the member-section structure intact when editing.
- `cpp-practice/` — scratch and practice files.

The code style is introductory C++: `using namespace std;`, `iostream`/`string`/`iomanip`, plain arrays and structs, interactive `cin`/`getline` input. Match that level; don't introduce modern/advanced features or extra files unless asked.

## Building and running

The repo is used on two machines synced through GitHub: Windows (PowerShell, MSYS2 g++ at `C:\msys64\ucrt64\bin\g++.exe`) and Linux Mint (bash, system g++). Binaries always go into a `bin/` folder **next to the source file** (gitignored along with `*.exe`).

```powershell
# Windows: compile (add -Run to also run)
powershell -NoProfile -ExecutionPolicy Bypass -File .vscode\build.ps1 <path\to\file.cpp> . -Run
```
```bash
# Linux: compile (add --run as 3rd arg to also run)
bash .vscode/build.sh <path/to/file.cpp> . --run
```

Both scripts run `g++ -fdiagnostics-color=always -g <file> -o <dir>/bin/<name>`. Programs read from stdin, so pipe input when running non-interactively, e.g. `printf 'Yogyakarta\n5\n' | ./bin/string_from_right` (one value per line when the program uses `getline`).

## Workspace files not to break

- `.vscode/build.ps1` and `.vscode/build.sh` must stay behaviorally equivalent; `build.sh` must keep LF line endings (enforced by `.gitattributes`).
- `.vscode/tasks.json` wires `Ctrl+Shift+B` to these scripts.
- `.vscode/settings.json` must contain only `code-runner.runInTerminal` and `code-runner.saveFileBeforeRun`. **Never add `code-runner.executorMap` there** — it's shared via Git and is OS-specific; it belongs in each machine's VS Code User Settings (see `notes.md`).

## Commit messages

Format `prefix: what you did` — short, English, verb first, naming the file/folder. Prefixes: `add:`, `fix:`, `update:`, `style:`, `refactor:`, `move:`, `docs:`, `chore:`, `wip:`. One commit per topic (two assignments → two commits). Full table and examples in `notes.md`.
