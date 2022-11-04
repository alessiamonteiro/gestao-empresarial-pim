gcc server.c \
./utils/montar-caminho-arquivo.utils.c \
./repository/buscar-usuarios.repository.c \
./repository/buscar-funcionarios.repository.c \
./repository/criar-usuario.repository.c \
./repository/criar-funcionario.repository.c \
./repository/criar-relatorio-funcionarios.repository.c \
./repository/buscar-cargos.repository.c \
./controller/buscar-usuarios.controller.c \
./controller/buscar-funcionarios.controller.c \
./controller/login-usuario.controller.c \
./controller/criar-usuario.controller.c \
./controller/criar-funcionario.controller.c \
./controller/criar-relatorio-funcionarios.controller.c \
./usecase/buscar-usuarios.usecase.c \
./usecase/buscar-funcionarios.usecase.c \
./usecase/criar-usuario.usecase.c \
./usecase/criar-funcionario.usecase.c \
./usecase/login-usuario.usecase.c \
./usecase/criar-relatorio-funcionarios.usecase.c \
./routes/router.c \
-o server

./server