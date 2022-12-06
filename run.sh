gcc -Wall main.c \
./repository/buscar-cargos.repository.c \
./service/buscar-usuarios.service.c \
./service/buscar-funcionarios.service.c \
./service/login-usuario.service.c \
./service/criar-usuario.service.c \
./service/criar-funcionario.service.c \
./service/criar-relatorio-funcionarios.service.c \
./service/criar-relatorio-clientes.service.c \
./service/criar-cliente.service.c \
./service/buscar-clientes.service.c \
\
./pages/menu.page.c \
./pages/login.page.c \
./pages/cadastro-usuario.page.c \
./pages/cadastro-funcionario.page.c \
./pages/perfil.page.c \
./pages/home.page.c \
./pages/buscar-usuarios.page.c \
./pages/buscar-funcionarios.page.c \
./pages/relatorios.page.c \
./pages/cadastro-cliente.page.c \
./pages/buscar-clientes.page.c \
./pages/consultas.page.c \
./pages/cadastros.page.c \
\
./utils/time.utils.c \
./utils/montar-caminho-arquivo.utils.c \
./utils/delay.utils.c \
./utils/voltar.utils.c \
./utils/validar-caracteres-invalidos.utils.c \
./utils/validar-usuario-invalido.utils.c \
./utils/formatar-cpf.utils.c \
./utils/encontrar-cargo.utils.c \
\
./client/socket-client.c -o start 

./start