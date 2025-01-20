# text editor in C
 - testo editor de 64bits em C
 - Programa básico em C para criar um editor de texto de 64 bits com uma interface gráfica no Windows 10. Usaremos a API do Windows (WinAPI) para desenvolver a interface gráfica. O código inclui funcionalidades básicas, como abrir, criar, modificar, salvar, salvar como, e exibir uma caixa de texto para o caminho do ficheiro.

1. **Criar a Janela Principal**:
   - Registamos uma classe de janela (`WNDCLASS`) e criamos a janela principal.
   - Configuramos o menu com opções como "Novo", "Abrir", "Salvar", "Salvar Como" e "Sair".

2. **Adicionar uma Caixa de Texto**:
   - Criamos uma caixa de texto com o estilo `ES_MULTILINE` para suportar múltiplas linhas.

3. **Adicionar Funcionalidades**:
   - Utilizamos diálogos padrão do Windows para abrir e salvar ficheiros.
   - Implementamos funções para manipular ficheiros (`OpenFile`, `SaveFile`, `SaveFileAs`).

4. **Gerir Mensagens**:
   - No `WindowProc`, tratamos mensagens como `WM_COMMAND` para responder aos cliques no menu.

---

### **Como Compilar**
1. Salve o código num ficheiro `editor_texto.c`.
2. Abra o terminal do Visual Studio Developer Command Prompt.
3. Execute:
   ```bash
   cl editor_texto.c /link user32.lib gdi32.lib comdlg32.lib
   ```
4. O executável `editor_texto.exe` será gerado e poderá ser executado diretamente no Windows 10.

---
### **Como usar o Dev-C++ para compilar o editor de texto em C**

 - O Dev-C++ é uma IDE gratuita e leve que facilita a compilação de programas em C/C++. Aqui está um guia passo a passo para compilar e executar o programa do editor de texto no Dev-C++:
---
#### 1. **Instalar o Dev-C++**
- Se ainda não tiver o Dev-C++, faça o download a partir de [Bloodshed Dev-C++](https://sourceforge.net/projects/orwelldevcpp/).
- Instale o programa seguindo os passos do instalador.

---

#### 2. **Abrir o Dev-C++**
- Inicie o programa.
- Na barra de menus, clique em **File > New > Project**.
- Escolha o tipo de projeto como **Console Application**, selecione a linguagem como **C**, e clique em **OK**.
- Escolha o local e o nome do projeto (exemplo: `EditorTextoDev`).

---

#### 3. **Inserir o Código**
- Na janela principal, apague o código que aparece por padrão.
- Copie o código do editor de texto que forneci e cole no editor de código do Dev-C++.

---

#### 4. **Configurar as Opções do Projeto**
- Vá a **Tools > Compiler Options** e certifique-se de que o compilador está configurado para suporte a **64 bits**.
- Para garantir que o programa compila corretamente com a API do Windows, adicione as bibliotecas necessárias:
  1. Vá para **Tools > Compiler Options > Add the following commands...**.
  2. Adicione as seguintes flags no campo de parâmetros adicionais:
     ```
     -mwindows -luser32 -lgdi32 -lcomdlg32
     ```
---
#### 5. **Salvar o Projeto**
- Clique em **File > Save Project As...** e escolha o local onde deseja salvar o projeto.

---

#### 6. **Compilar o Programa**
- Clique em **Execute > Compile & Run** ou pressione a tecla **F11**.
- O Dev-C++ irá compilar o programa e, se não houver erros, executará o editor de texto diretamente.

---

#### 7. **Testar o Programa**
- Quando o programa abrir, verá a interface gráfica do editor de texto com as opções no menu.
- Pode criar, abrir e salvar ficheiros de texto, testando as funcionalidades implementadas.

---

### **Nota Importante**
- Certifique-se de que o Dev-C++ está configurado para usar o compilador **MinGW** correto, que suporta a API do Windows.
- Caso o editor mostre erros relacionados às bibliotecas do Windows, confirme que os nomes das bibliotecas (como `user32`, `gdi32`, e `comdlg32`) foram incluídos corretamente nas opções do compilador.

 

