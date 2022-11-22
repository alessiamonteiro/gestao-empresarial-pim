gcc server.c \
./utils/montar-caminho-arquivo.utils.c \
./utils/crypt.utils.c \
./repository/buscar-usuarios.repository.c \
./repository/buscar-funcionarios.repository.c \
./repository/criar-usuario.repository.c \
./repository/criar-funcionario.repository.c \
./repository/criar-relatorio-funcionarios.repository.c \
./repository/buscar-cargos.repository.c \
./repository/criar-cliente.repository.c \
./repository/buscar-clientes.repository.c \
./controller/buscar-usuarios.controller.c \
./controller/buscar-funcionarios.controller.c \
./controller/login-usuario.controller.c \
./controller/criar-usuario.controller.c \
./controller/criar-funcionario.controller.c \
./controller/criar-relatorio-funcionarios.controller.c \
./controller/criar-cliente.controller.c \
./controller/buscar-clientes.controller.c \
./usecase/buscar-usuarios.usecase.c \
./usecase/buscar-funcionarios.usecase.c \
./usecase/criar-usuario.usecase.c \
./usecase/criar-funcionario.usecase.c \
./usecase/login-usuario.usecase.c \
./usecase/criar-relatorio-funcionarios.usecase.c \
./usecase/criar-cliente.usecase.c \
./usecase/buscar-clientes.usecase.c \
./routes/router.c \
-o server

./server