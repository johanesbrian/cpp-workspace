# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this repo is

A personal C++ coursework workspace. Every `.cpp` file is a standalone, single-file console program with its own `main()`; there is no project-wide build system, library code, or test suite. Files are grouped by course and assignment:

- `programming-laboratory/assignment-NN/`, `programming-tasks/assignment-NN/` — course assignments; most files open with a block comment stating the problem.
- `programming-laboratory/group-project/main.cpp` — the one larger program: a menu-driven event finder. All state is an `Event events[MAX_EVENTS]` array plus a `count` declared in `main()` and passed to each feature function (no globals, no file persistence). Features are labeled `Feature A`–`I` in section comments, each tagged `(Member N)`; keep that structure and attribution intact when editing. All numeric input goes through the validating helpers (`readIntInRange`, `readNonNegativeDouble`, …), so reuse them rather than using raw `cin >>`.
- `cpp-practice/` — scratch and practice files.

The code style is introductory C++: `using namespace std;`, `iostream`/`string`/`iomanip`/`limits`, plain arrays and structs, interactive `cin`/`getline` input. Match that level; don't introduce modern/advanced features or extra files unless asked.

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

Both scripts run `g++ -fdiagnostics-color=always -g <file> -o <dir>/bin/<name>`. Programs read from stdin, so pipe input when running non-interactively, e.g. `printf 'Yogyakarta\n5\n' | ./bin/string_from_right` (one value per line when the program uses `getline`). For the group project, pipe a full menu session that ends with `9` (Exit), otherwise the loop waits for input forever.

On Windows, Git Bash also has MSYS2 g++ on `PATH`, so `build.sh` works there too (g++ appends `.exe` to the output automatically).

## Workspace files not to break

- `.vscode/build.ps1` and `.vscode/build.sh` must stay behaviorally equivalent; `build.sh` must keep LF line endings (enforced by `.gitattributes`).
- `.vscode/tasks.json` wires `Ctrl+Shift+B` to these scripts.
- `.vscode/settings.json` must contain only `code-runner.runInTerminal` and `code-runner.saveFileBeforeRun`. **Never add `code-runner.executorMap` there** — it's shared via Git and is OS-specific; it belongs in each machine's VS Code User Settings (see `notes.md`).

## Commit messages

Format `prefix: what you did` — short, English, verb first, naming the file/folder. Prefixes: `add:`, `fix:`, `update:`, `style:`, `refactor:`, `move:`, `docs:`, `chore:`, `wip:`. One commit per topic (two assignments → two commits). Full table and examples in `notes.md`.
