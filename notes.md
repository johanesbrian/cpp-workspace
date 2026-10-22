# cpp-workspace Notes

**PC** = Windows (PowerShell, g++ from MSYS2) · **Laptop** = Linux Mint (bash, g++ from `build-essential`) · synced through GitHub

## Daily Workflow
1. `git pull` ← ALWAYS first, especially after switching PC ↔ laptop
2. Write code, then:
   - `Ctrl + Alt + N` → compile + run
   - `Ctrl + Shift + B` → compile only
3. `git add .` → `git commit -m "what changed"` → `git push`

`bin/` is created automatically **next to the `.cpp`** (e.g. `programming-tasks/assignment-02/bin`). New course or assignment folders need no setup. `bin/` is ignored by Git.

## Terminal
| Action | Windows (PowerShell) | Linux (bash) |
|---|---|---|
| Current folder | `pwd` | `pwd` |
| List contents | `ls` | `ls` |
| Enter folder / go up | `cd name` / `cd ..` | `cd name` / `cd ..` |
| Full path | `cd D:\cpp-workspace` | `cd ~/Documents/cpp-workspace` |
| Previous folder | `cd -` (PowerShell 7+) | `cd -` |
| Run program | `.\bin\file` | `./bin/file` |

Manual compile (terminal inside the `.cpp` folder, same on both): `g++ file.cpp -o bin/file` (run `mkdir bin` first if it doesn't exist)

## Git Commands
| Command | Use |
|---|---|
| `git status` | what changed (check before committing) |
| `git diff` / `git diff --staged` | exact changes before / after `add` |
| `git log --oneline` | short commit history |
| `git reset HEAD~1` | undo last commit, keep the changes |
| `git checkout -- file` | discard changes in a file |
| `git remote -v` | which GitHub repo this folder is connected to |
| `git clone <url>` | copy the repo to a new device |

## Commit Messages
Pattern: `prefix: what you did` (English, short, start with a verb, mention the file/folder)

| Prefix | Use for | Example |
|---|---|---|
| `add:` | new file or assignment | `add: assignment-05 pyramid and diamond patterns` |
| `fix:` | bug or error fix | `fix: pyramid not printing new lines` |
| `update:` | change existing code | `update: final grade now shows 2 decimal places` |
| `update:` | small random edits | `update: minor tweaks in assignment-03` |
| `style:` | spacing, indentation, comments only | `style: tidy up formatting in pyramid_output.cpp` |
| `refactor:` | rename/reorganize code, same result | `refactor: rename variables in final_grade.cpp` |
| `move:` | move or rename files/folders | `move: practicum files into assignment folders` |
| `docs:` | notes.md or comments | `docs: add commit message examples` |
| `chore:` | setup, config, cleanups | `chore: small cleanups across programming-tasks` |
| `wip:` | unfinished (e.g. switching PC ↔ laptop) | `wip: book stock sale, input part done` |

- One commit = one topic (two different assignments → two commits)
- Avoid `update`, `fix`, `asdf` alone
- Forgot what changed? `git status` (which files) → `git diff` (which lines)

## Workspace Files (don't break these)
- `.vscode/build.ps1` (Windows) and `.vscode/build.sh` (Linux) → build scripts
- `.vscode/tasks.json` → `Ctrl + Shift + B`
- `.vscode/settings.json` → only `runInTerminal` and `saveFileBeforeRun`. **Never put `executorMap` here** (it's shared through GitHub and overrides User Settings)
- `.gitignore` → `bin/` and `*.exe`
- `.gitattributes` → `*.sh text eol=lf` (keeps `build.sh` working on Linux)

## One-Time Setup on a Device
1. Install g++ → Windows: MSYS2 (`C:\msys64\ucrt64\bin\g++.exe`) · Linux: `sudo apt install build-essential`
2. VS Code extensions: **C/C++**, **Code Runner**
3. `git config --global user.name "Your Name"` and `git config --global user.email "you@example.com"`
4. `Ctrl + Shift + P` → **Open User Settings (JSON)** → add inside `{ }`:

Windows:
```json
"code-runner.executorMap": {
    "cpp": "powershell -NoProfile -ExecutionPolicy Bypass -File $workspaceRoot\\.vscode\\build.ps1 $fullFileName $workspaceRoot -Run"
},
"settingsSync.ignoredSettings": ["code-runner.executorMap"]
```
Linux:
```json
"code-runner.executorMap": {
    "cpp": "bash $workspaceRoot/.vscode/build.sh $fullFileName $workspaceRoot --run"
},
"settingsSync.ignoredSettings": ["code-runner.executorMap"]
```
`ignoredSettings` stops VS Code Settings Sync from copying the Windows command to Linux (and the other way around).

## Troubleshooting
| Problem | Fix |
|---|---|
| `.exe` appears right next to the `.cpp` | Code Runner not set up on this device → One-Time Setup step 4 |
| `powershell: command not found` on Linux | `executorMap` is in `.vscode/settings.json` or Settings Sync overwrote it → check workspace settings first, then User Settings |
| "Duplicate object key" in JSON | the same key is written twice → delete one |
| `$'\r': command not found` on Linux | `build.sh` has Windows line endings → click `CRLF` at the bottom right → `LF` → save |
| Can't delete `.exe` (EPERM) | the program is still running → `Ctrl + C` in the terminal |
| Compile error but the code looks right | file not saved → `Ctrl + S` |
| `git pull`: "no tracking information" | `git branch --set-upstream-to=origin/main main` |
| Creating a file made new folders | don't type `/` or `\` in the file name |

## Rarely Needed
**Wipe all commit history (files stay).** ⚠️ Permanent. Back up first.
```bash
git checkout --orphan fresh
git rm -r --cached . -q
git add -A
git status                  # no bin/ or .exe allowed
git commit -m "Initial commit"
git branch -D main
git branch -m main
git push -u -f origin main
```
On the other device: `git fetch` then `git reset --hard origin/main` (not `git pull`).

**Connect an existing folder to a new, empty GitHub repo:**
```bash
git init
git add .
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/username/repo-name.git
git push -u origin main
```

**Branches (group projects):** `git branch` (list) · `git checkout -b name` (create + switch) · `git checkout name` (switch) · `git merge name` (merge into current)

**Token in remote URL:** `git remote set-url origin https://johanesbrian:TOKEN@github.com/johanesbrian/cpp-workspace.git` ⚠️ stored as plain text in `.git/config`, never write the real token here.

## VS Code
- `` Ctrl + ` `` terminal · `Ctrl + Shift + P` command palette · `Ctrl + S` save · `code .` open folder from terminal
- Explorer badges: **U** new (untracked) · **A** staged · **M** modified · **D** deleted