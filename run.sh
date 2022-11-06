gcc -Wall main.c \
./service/buscar-usuarios.service.c \
./service/buscar-funcionarios.service.c \
./service/login-usuario.service.c \
./service/criar-usuario.service.c \
./service/criar-funcionario.service.c \
./service/criar-relatorio-funcionarios.service.c \
./service/criar-cliente.service.c \
./pages/menu.page.c \
./pages/login.page.c \
./pages/cadastro.page.c \
./pages/cadastro-funcionario.page.c \
./pages/perfil.page.c \
./pages/home.page.c \
./pages/buscar-usuarios.page.c \
./pages/buscar-funcionarios.page.c \
./pages/relatorios.page.c \
./pages/cadastro-cliente.page.c \
./utils/time.utils.c \
./utils/montar-caminho-arquivo.utils.c \
./utils/delay.utils.c \
./client/socket-client.c -o start 

./start