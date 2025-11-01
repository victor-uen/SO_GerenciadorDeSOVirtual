# SO_GerenciadorDeSOVirtual

## Desafio Proposto

Nesta ideia, precisamos desenvolver uma aplicação que será usada como Alocador
de Memória Virtual. Toda a alocação de dados de memória será feita juntamente
com a criação da Tabela de Páginas, a Política de Substituição de Páginas, etc.
O Gerenciamento de Memória pode ser visto neste caso.
Não há envolvimento de hardware e será parecido com o sistema operacional Linux
e não com qualquer outro sistema operacional.
Ideia de desenvolvimento:
 Use algoritmos de substituição de página para encontrar falhas de página neste
ponto.
 Você precisa usar a troca com a linguagem de codificação para alterar dados
entre as ferramentas de memória e disco.
 Use a política de substituição de memória "primeiro a entrar, primeiro a sair".


## Gerenciador de Memória Virtual (FIFO)

Simulação simples de um sistema de memória virtual em C.

### Funcionalidades:
- Tabela de páginas
- Memória física simulada
- Substituição de páginas FIFO
- Contagem de page faults e evictions

