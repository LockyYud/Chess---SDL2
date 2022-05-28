# Chess - A SDL2 C++ Game

## Introduction

A game project made with SDL2 C++.

## Technologies

Project uses:

- Visual Studio Code (VSCode).
- SDL2 image devel 2.0.5 mingw.
- SDL2 ttf devel 2.0.18 mingw.
- SDL2 mixer devel 2.0.4 mingw.
- SDL2 devel 2.0.20 mingw.

## How to compile and play

- **Windows 64bit**: 
    - Requirements:
        - VSCode.
        - Makefile on Windows.
        - MinGW-w64.
    - Clone this repository to your computer.
    - Open command line inside the cloned folder.
    - Run `make`.
    - `main.exe` file will be generated. Open the file to run the game.



## Contents

#### Basic rules of chess

1. Trong một ván cờ, khi tiến hành các nước đi, các kỳ thủ chỉ được sử dụng một tay duy nhất, và trong nước “nhập thành” thì đặc biệt phải dùng duy nhất tay phải.

2. Khi đến lượt đi của mình, các kỳ thủ có thể sửa cho đúng ô các quân cờ với điều kiện phải thông báo trước cho đối thủ. (Nói: Sửa hoặc Tôi sửa rồi mới tiến hành sửa quân).

3. Bên cạnh đó, khi còn đang trong lượt chơi của mình, nếu:

- Không yêu cầu được sửa mà kỳ thủ chạm tay vào quân cờ nào thì bắt buộc phải đi quân đó.
- Tương tự, khi đụng vào quân cờ nào của đối thủ nếu có thể ăn được cũng bắt buộc phải ăn.
4. Trong nước nhập thành nếu:

- Kỳ thủ đã chạm vào Vua của mình và Xe ở phía nào thì phải nhập thành về phía đó, nếu có thể tiến hành nhập thành hợp lệ. (Xem về nước nhập thành và các nguyên tắc nhập thành hợp lệ)
- Trong nước nhập thành, nếu kỳ thủ không chạm vào Vua trước mà chạm Xe trước thì nước nhập thành đó không được tiến hành và bắt buộc phải di chuyển xe (điều #3) do sai nguyên tắc nhập thành.
Khi Kỳ thủ đã chạm vào quân Vua nhưng không nhập thành được do vi phạm nguyên tắc nhập thành thì bắt buộc phải di chuyển quân Vua. Nếu vua không có nước đi hợp lệ, kỳ thủ có thể đi quân khác.

5. Nếu quân đã chạm đã chạm không có nước di chuyển hoặc ăn quân hợp lệ thì kỳ thủ có thể đi một nước cờ khác và tính “1 lỗi kỹ thuật”.

6. Khi đối thủ vi phạm các luật này phải bắt ngay, đến nước mới thì kỳ thủ sẽ mất quyền khiếu nại.

**Link video introduce game**
- https://www.youtube.com/watch?v=B0hHAKPgDkM