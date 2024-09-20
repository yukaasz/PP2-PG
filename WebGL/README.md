# PP2 - WebGL
## Conceito do projeto
Este projeto foi realizado com a finalidade de melhor compreender o funcionamento do método WebGL. O objetivo do trabalho era visualizar dois objetos OBJ 3D. Para isso, o grupo utilizou HTML e JavaScript para que fossem visualizados dois objetos no mesmo plano, sendo eles dois livros conforme vistos no exemplo fornecido 
## Pré-Requisitos e recursos utilizados
Foram usados como base os códigos apresentados no site WebGL2 Fundamentals disponível no link: "https://webgl2fundamentals.org/"
## Passo a passo
O projeto foi feito seguindo os seguintes requisitos:
  * Visualizar dois objetos OBJ 3D
  * Cada objeto teria que ter movimentos independentes.

Tomamos como base o código que carrega a imagem do objeto book.obj disponível na página "https://webgl2fundamentals.org/webgl/lessons/webgl-load-obj.html". A partir dele, estudamos o código fornecido e alteramos ele para que pudesse atender os requisitos pedidos.

Para que pudéssemos visualizar dois objetos, alteramos a função render. Como o código original possuia apenas um objeto, tivemos que inicializar com uma matriz identidade para poder mover o objeto de lugar com a função `m4.translate(u_world, -0.2, 0, 0)` translate, escolhemos deslocar o objeto1 0,2 para esquerda (-0,2 no eixo x) e o objeto2 0,2 para a direita (0,2 no eixo x). 
Para o objeto1, mantivemos a rotação em torno do eixo y com a função `m4.multiply(u_world, m4.yRotation(time))`, e para o objeto2, mudamos a rotação para girar em torno do eixo x com a função `m4.multiply(u_world2, m4.xRotation(time))`.
No fim, fazemos um `translate(u_world, ...objOffset)` para ajustar a posição final do objeto, levando em consideração a translação e a rotação já aplicadas.
## Execução
Para executar o projeto em seu terminal, vá até o diretório raiz, e abra o arquivo "webgl-load-obj-w-vertex-colors.html". Ele abrirá um .html no navegador que mostra o resultado do código alterado seguindo as duas restrições definidas.
## Autores
* Daniella Yuka Hirosue
* João Vitor Averaldo Antunes
* Lara Oliveira Luzeiro
* Renan Yugo Ueda
