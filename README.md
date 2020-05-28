<h1>Universidade Federal de Minas Gerais</h1>
<h2>Ciencia da Computação</h2>

<h3>Programação e Desenvolvimento de Software II</h3>


## **Jogo da Vida (Game of Life)** 

Conway escolheu suas regras cuidadosamente, após um longo período de experimentos, para satisfazer três critérios:

1. **Não** deve haver nenhuma imagem inicial para a qual haja uma prova **imediata ou trivial** de que a população pode crescer sem limite.

2. Deve haver imagens iniciais que aparentemente cresçam sem limite.

3. Deve haver imagens iniciais simples que cresçam e mudem por um período de tempo considerável antes de chegar a um fim das possíveis formas:

   1.**Sumindo completamente** (por superpopulação ou por ficarem muito distantes)
   
   2.**Estacionando em uma configuração estável que se mantem imutável para sempre**, ou entrando em uma fase de oscilação na qual são repetidos ciclos infinitos de período dois ou mais.


Em outras palavras, as regras deviam tornar o comportamento das populações ao mesmo tempo interessante e imprevisível.

<b1>As regras são simples e elegantes:</b1>

1. Qualquer célula viva com menos de dois vizinhos vivos morre de solidão.
2. Qualquer célula viva com mais de três vizinhos vivos morre de superpopulação.
3. Qualquer célula morta com exatamente três vizinhos vivos se torna uma célula viva.
4. Qualquer célula viva com dois ou três vizinhos vivos continua no mesmo estado para a próxima geração.

  É importante entender que todos os nascimentos e mortes ocorrem simultaneamente. Juntos eles constituem uma geração ou, como podemos chamá-los, um "instante" na história da vida completa da configuração inicial.

---
