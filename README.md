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

#### How to play

Nắm vững các quân cờ và cách di chuyển của chúng. Mỗi loại quân cờ có các cách di chuyển khác nhau. Dưới đây là tên của các quân cờ kèm theo cách di chuyển của chúng (một số ngoại lệ sẽ được đề cập ở phần sau):
    - Tốt: Quân cờ cơ bản nhất trong cờ vua (mỗi bên có 8 quân Tốt). Trong lần di chuyển đầu tiên, Tốt có thể tiến về phía trước một hoặc hai ô, nhưng chỉ được tiến lên một ô trong các lần sau đó. Tốt chỉ tấn công được các quân khác nằm chéo về phía trước một ô và không thể đi lùi.
    - Xe: Xe trông giống như một tòa tháp trong lâu đài. Nó có thể đi ngang hoặc đi dọc tùy ý nếu không bị cản. Xe có thể tấn công các quân nằm trên đường đi của nó.
    - Mã: Biểu tượng của Mã là hình con ngựa. Đây cũng là quân cờ phức tạp nhất. Mã đi theo hình chữ 'L' được tạo bởi hai ô ngang và một ô dọc, hoặc một ô ngang và hai ô dọc, chữ 'L' này có thể ngả theo mọi hướng. Mã là quân duy nhất có thể nhảy qua đầu các quân khác. Nó chỉ tấn công những quân nằm trong các ô mà nó có thể nhảy tới.
    - Tượng: Tượng chỉ đi chéo, nhưng có thể đi bao nhiêu ô tùy ý trừ phi bị cản. Quân cờ này có hình như chiếc mũ của vị giám mục Thiên Chúa giáo.
    - Hậu: Hậu là quân quyền lực nhất trên bàn cờ (thường có vương miện nữ tính hơn quân Vua). Nó có thể đi ngang, dọc, hoặc chéo tùy ý và tấn công theo mọi hướng.
    - Vua: Vua chỉ có thể đi một ô mỗi lượt, di chuyển theo mọi hướng. Cách quân Vua tấn công cũng tương tự như vậy. Đây là quân cờ mà bạn bằng mọi giá không thể để mất, vì bạn sẽ thua cuộc nếu mất Vua.
    - Ghi nhớ điểm mạnh của từng quân cờ.
    - Vua là quân cờ quan trọng nhất và cần được bảo vệ.
    - Hậu là quân linh hoạt nhất và cũng là quân hỗ trợ các quân khác tốt nhất, thường được dùng để tấn công bắt đôi. Hậu kết hợp cách di chuyển của cả Tượng và Xe trong cùng một quân cờ. Đây là quân quan trọng tương tự quân Vua.
    - Mã là quân cờ hữu hiệu để ra đòn tấn công bất ngờ hoặc bắt đôi. Quy luật di chuyển của Mã thường khiến những người mới chơi lúng túng và ít được họ lưu ý tới.
    - Tượng là quân cờ hữu hiệu khi ở vị trí mở. Tuy nhiên, nhiều người mới chơi thường không đánh giá cao quân Tượng và không tận dụng nó.
    - Xe là quân cờ mạnh và chúng có phạm vi di chuyển rộng. Xe hoạt động tốt nhất trên các hàng và cột trống.
    - Tốt dường như không có giá trị, nhưng chúng có thể được dùng để bẫy đối phương một cách hiệu quả, ví dụ như thí tốt để ăn quân khác mạnh hơn. Nếu biết cách sử dụng, bạn có thể dùng Tốt để chiếu tướng hết cờ!