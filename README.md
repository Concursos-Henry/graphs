# graphs

Aula sobre grafos.

## Instalação

1. Baixar graphviz e colocar a pasta bin no PATH do sistema: https://www.graphviz.org/
2. Baixar MingW e colocar a pasta bin no PATH do sistema: https://sourceforge.net/projects/mingw/
3. Rodar os seguintes comandos:

   ```bash
   conda env create -f environment.yml
   conda activate graphs
   install_c_kernel --user
   ```

## Gerando os slides

Para gerar os slides da aula, siga o seguinte passo-a-passo:

1. Abra um console do Python na pasta do projeto
2. Digite o seguinte comando no console:

   ```bash
   jupyter nbconvert --to slides aula.ipynb --output "aula" --output-dir="docs"
   ``` 

3. Caso você queira gerar os slides e vê-los imediatamente, digite o seguinte comando:
   
   ```bash
   jupyter nbconvert --to slides aula.ipynb --output "aula" --output-dir="docs" --post serve
   ``` 