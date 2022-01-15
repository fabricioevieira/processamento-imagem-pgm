# Projeto – Processamento de Imagens usando arquivos PGM #
Disciplina: Algoritmos e Técnicas de Programação II

---

### Introdução: ###

Uma imagem em tons de cinza pode ser representada por uma matriz bidimensional, tal que cada elemento desta matriz (também chamado de pixel) possui um valor de 0 (preto) a 255 (branco). Arquivos de formatos de imagens (como BMP, JPG, PNG), incluem além desta matriz da imagem, outras informações relevantes sobre a imagem. Por exemplo, no formato PGM, um dos mais simples encontrados, a imagem pode ser representada pela seguinte
estrutura:

```
<tipo do arquivo>

<número de colunas> <número de linhas>

<número máximo de tons de cinza>

<matriz da imagem>
```

onde `<tipo do arquivo>` é um código de dois caracteres (p. ex. "P2"), `<número de colunas>` e `<número de linhas>`indicam o tamanho da matriz de imagem, `<número máximo de tons de cinza>` contém uma informação sobre a quantização da imagem e, finalmente, `<matriz da imagem>` contém os valores dos pixels, do pixel superior esquerdo ao pixel inferior direito.

---

### O que devo fazer: ###
Faça um programa que carregue uma imagem PGM, faça as operações descritas abaixo e salve a imagem resultante em cada passo em outro arquivo PGM. As operações são:
1. **Limiarização:** Verifique para cada pixel se seu valor é maior que um limiar (p. ex. 150). Em caso positivo, substitua o seu valor para 255. Caso contrário, defina-o para zero;

2. **Negativo:** Substitua o valor v de cada pixel, por (255 - v);

3. **Histograma:** Gere um histograma da imagem inicial e salve em um arquivo *.txt*. Um histograma é a contagem de pixels que cada tonalidade de cinza possui.

#### Dicas: ####
1) Para visualizar arquivos PGM você pode procurar algum editor de imagens que aceita este tipo de arquivo.

2) Um arquivo PGM de exemplo está disponível. Tente abrir o arquivo em um editor de texto comum para você ver a
estrutura acima.
3) É altamente recomendável que o aluno faça um código bem organizado, utilizando funções para cada operação
acima, além de outras auxiliares, tal como abrir o arquivo e carregar em uma matriz e salvar um arquivo .PGM.

---

### O que devo entregar: ###

1) Código fonte produzido
2) Imagens de exemplo utilizadas e resultados gerados