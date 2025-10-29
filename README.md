🎮 so_long — Projeto 42 (com MLX42)

O so_long é um jogo 2D desenvolvido em C utilizando a MLX42, uma biblioteca gráfica moderna baseada em GLFW e OpenGL.
O objetivo do jogo é guiar o personagem até a saída, coletando todos os itens no caminho e evitando obstáculos.

---
📍Objetivo do Projeto

O projeto tem como propósito introduzir conceitos de programação gráfica, manipulação de eventos e renderização em tempo real.
Além disso, reforça práticas de gerenciamento de memória, leitura de arquivos e organização modular em C.
---

⚙️ Compilação e Execução

Certifique-se de ter a MLX42 instalada e linkada corretamente.
No terminal:
```
make
```

▶️ Executar o jogo
```
./so_long maps/mandatory_map/example_map.ber
```

🗺️ Estrutura do Mapa

Os mapas devem estar no formato .ber e seguir as regras abaixo:

Símbolo	Significado:
```
0	Espaço vazio
1	Parede
C	Item colecionável
E	Saída
P	Posição inicial do jogador
```

🧾 Exemplo:
```
111111
1P0C01
1000E1
111111
```
---
🧠 Funcionalidades

✅ Leitura e validação de mapas .ber

✅ Verificação de caminho válido (player → coletáveis → saída)

✅ Renderização de sprites com MLX42

✅ Movimentação suave via teclado (W, A, S, D)

✅ Contador de movimentos no terminal

✅ Gerenciamento completo de memória (sem leaks)

✅ Tratamento robusto de erros
---

🗂️ Estrutura do Projeto
```
/
├── include/         # Cabeçalhos (.h)
├── maps/            # Mapas de teste (.ber)
├── src/
│   ├── parsing/     # Leitura e validação de mapa
│   ├── game/        # Lógica principal do jogo
│   ├── render/      # Desenho e sprites na tela
│   └── utils/       # Funções auxiliares
├── textures/        # Sprites e imagens do jogo
├── Makefile         # Script de compilação
└── README.md        # Este arquivo
```

🎮 Controles - Tecla	Ação:
```
W	Mover para cima
A	Mover para esquerda
S	Mover para baixo
D	Mover para direita
ESC	Fechar o jogo
```

🧰 Tecnologias Utilizadas

C	Linguagem principal;
MLX42	Renderização gráfica e controle de eventos;
Makefile	Automação da compilação;

🧩 Como Rodar o Projeto

Instale as dependências:
```
sudo apt update
sudo apt install cmake libglfw3-dev
```

Clone o repositório:
```
git clone https://github.com/ysabela001/so_long.git
cd so_long
```

Compile:
```
make
```

Execute:
```
./so_long maps/mandatory_map/example_map.ber
```
