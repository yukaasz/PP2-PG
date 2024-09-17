# PP2 - Ray Tracing
## Conceito do projeto
Este projeto foi realizado com a finalidade de melhor compreender o funcionamento do método Ray Tracing. Nele, nós tivemos a ideia de simular a movimentação de um "Pêndulo de Newton" através dos mecanismos oferecidos no livro que tomamos como base.
## Pré-Requisitos e recursos utilizados
O grupo utilizou linguagem C++ para desenvolver a implementação completa do projeto, utilizando apenas as bibiliotecas:
1. `<cmath>`
2. `<cstdlib>`
3. `<iostream>`
4. `<limits>`
5. `<memory>`
6. `<vector>`

Foram usados como base os códigos apresentados no livro "Ray Tracing in One Weekend" da série de livros online dos autores: Peter Shirley, Trevor David Black, Steve Hollasch. Acessado pelo link: "https://raytracing.github.io/books/RayTracingInOneWeekend.html"
## Passo a passo
Para a montagem do cenário, planejou-se simular o funcionamento de um “Pêndulo de Newton” com 5 esferas de mesmo raio, em que as presentes nas extremidades se movimentaram em formato circular, assim como no famoso experimento.
	No desenvolvimento do ambiente, foi usado o código proposto no documento “Ray Tracing In One Weekend”, o qual discorre sobre a implementação de um sistema de processamento gráfico voltado a geração de imagens através do Ray Tracing, introduzindo o conceito através da geração de esferas, texturas e posicionamento de câmera.
	A partir disso, com uso da biblioteca construída ao longo da leitura do livro, foi possível posicionar as esferas no cenário, lado a lado. Ademais, foram definidos 3 diferentes tipos de materiais, dando texturas às esferas do pêndulo: a superfície lambertiana, metálica e dielétrica. Desse modo, uma superfície lambertiana possui uma aparência fosca, ao apresentar a mesma radiância, independentemente do ângulo. A superfície metálica é obtida ao refletir os raios incidentes sobre a superfície da esfera de forma semelhante a um espelho, adicionando um grau de “fuzz”, gerando certo ruído. Por fim, a superfície dielétrica é a responsável por simular objetos translúcidos através do princípio da refração, além de refletir os raios que passam de relance.
 Para a animação, foram gerados 10 quadros, sendo eles a esfera da extremidade na iminência do movimento, quadros intermediários relativos ao seu movimento circular (cujo centro, ou seja, a posição da corda que seguraria a esfera, está localizado 3 raios acima dela) e um último quadro para o momento do contato com as outras esferas. Desse modo, as imagens foram reunidas em um editor de vídeo a uma taxa de 15 quadros por segundo. Após isso, as imagens foram refletidas para que fosse possível simular o movimento da outra extremidade mais facilmente, e, após um movimento completo do pêndulo, o vídeo gerado foi retrocedido, a fim de gerar um efeito de loop.
## Execução
Para executar o projeto em seu terminal, vá até o diretório que o arquivo main.cpp está presente e execute para compilar o código:
```
cmake -- build build
```
Após isso, uma imagem relativa ao cenário montado será gerada executando o comando:
```
build/inOneWeekend > image.ppm
```
A imagem ppm será salva no diretório raíz. Para visualizar a imagem gerada é necessário usar algum leitor de imagem apropriado para este formato.
## Autores
* Daniella Yuka Hirosue
* João Vitor Averaldo Antunes
* Lara Oliveira Luzeiro
* Renan Yugo Ueda

## Imagens/screenshot

`` mudar depois
![Imagem1](screenshots/imagem1.png)
![Imagem2](screenshots/imagem2.png)
![Imagem3](screenshots/imagem3.png)
