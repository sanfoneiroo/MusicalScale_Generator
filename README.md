# Scale Gen – Gerador de Escalas Musicais em Arduino

O **Scale.gen** é um gerador de escalas musicais baseado em Arduino, pensado como uma ferramenta **didática e prática** para estudar tonalidades, escalas e escuta musical.

O projeto utiliza:
- um **LCD Keypad Shield 16x2**
- um **buzzer passivo**
- e um **motor musical próprio**, sem bibliotecas externas de áudio

A interface é simples e musical: escolha o **tom**, a **escala** e aperte **PLAY**.

---

## Conceito

O foco do projeto é musical.

Mais do que apenas tocar notas, o **Scale.gen** implementa uma arquitetura que separa claramente:

- **definição musical das escalas**
- **cálculo das notas a partir dos intervalos**
- **tratamento correto da grafia musical**
- **interface e interação com o usuário**

O motor musical é responsável por transformar uma definição abstrata de escala em notas concretas para qualquer tonalidade, respeitando princípios da teoria musical.

---

## Hardware utilizado

- Arduino Uno (ou compatível)
- LCD Keypad Shield 16x2
- Buzzer passivo
- LED do próprio shield

### Ligações principais

| Função        | Pino |
|--------------|------|
| LCD          | Shield padrão |
| Botões       | A0 (analógico) |
| Buzzer       | D3 |

---

## Mapeamento dos botões (LCD Shield)

| Botão  | Função |
|------|--------|
| UP    | Tom + |
| DOWN  | Tom − |
| RIGHT | Escala + |
| LEFT  | Escala − |
| SELECT| Play |

---

## Interface

- **Linha 1:** Tom + nome da escala  
- **Linha 2:** instrução / exibição da escala tocada  

Durante o `PLAY`, a escala é:
1. impressa no Serial
2. exibida no LCD
3. tocada no buzzer

---

## Estrutura do projeto

/src
├── main.ino
├── notes.h
├── engine.h / engine.cpp
├── scales.h
├── interface.h / interface.cpp

## Objetivo do projeto

O **Scale.gen** foi concebido como uma ferramenta prática para:

- explorar escalas em diferentes tonalidades
- testar rapidamente novas estruturas escalares
- validar grafia musical correta em sistemas computacionais
- servir de base para outros projetos musicais embarcados

A arquitetura prioriza **clareza musical**, **extensibilidade** e **separação entre música e interface**.

---

## Flexibilidade da interface

A arquitetura do projeto permite **trocar completamente a lógica de interface** — tanto de botões quanto de display — de forma segura, sem qualquer impacto no motor musical ou nas bibliotecas de escalas.

Isso inclui, por exemplo:
- substituir o LCD 16x2 por outro tipo de display
- alterar o mapeamento ou tipo de botões
- migrar para encoder rotativo, teclado matricial ou interface serial
- criar múltiplas interfaces usando o mesmo `engine`

Desde que a nova interface respeite a API exposta pelo motor musical, o **engine e as bibliotecas próprias permanecem inalterados**, garantindo estabilidade e coerência musical.

---


## Autor

**Erwin Kuchenbecker**  
Músico, educador e desenvolvedor  

Projeto voltado à interseção entre teoria musical, programação e sistemas embarcados.

---

## Licença

Projeto aberto para fins educacionais e experimentais.  
Use, modifique, estude — e toque música