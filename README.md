# LP1 Challenge

**Developers: Bruno Garcia and Vinicius Costa**

The challenge:

Um	banco	armazena	dados	de	seus	clientes,	suas	contas	correntes	e	a	movimentação	de	cada	conta.	
Pensando	na	movimentação	que	os	clientes	 fazem	em	suas	contas	vamos	controlar	nesse	sistema	os	
depósitos	e	saques	nas	contas	correntes,	para	isso	vamos	implementar	algumas	funcionalidades.

• 	 Defina uma	 estrutura	 que	 armazene	 os	 dados	 das	 contas	 dos	 clientes	 com	 número	 da	
conta(deve	 ser	 único e	 gerado	 pelo	 próprio	 programa),	 saldo,	 número	 da	 agência, nome	 do	
cliente,	tipo	de	cliente	e	numa	união	o	cpf	ou	cnpj do	cliente que	pode	ser	uma	pessoa	física	ou	
jurídica.	Defina	também	um	typedef	para	estrutura	criada.

• 	Faça	 um	menu	 no	 programa	 principal	 para	 as	 diversas	 funcionalidades	propostas para	
essa	 avaliação	 (Inserção/Impressão/Busca	 Cliente/Busca	 Agência/Depósito/Saque/Desafio).	
Inicialmente,	 crie	 um	 vetor de	 contas,	 leia	 e	 armazene	 um	 certo	 numero	 de	 contas	
(diretamente	no	programa	principal	ou	numa	 função). O	número	de	contas	cadastradas	deve	
ser	definido	pelo	usuário.

• 	Faça	uma	função	que	liste	todas	as	contas	cadastradas	com	seus	dados.

• 	Faça	uma	função	que	dado	um	número	de	conta,	imprima os	seguintes	dados	do	cliente: o
número	 da	 conta,	 o saldo	 da	 conta, o	 nome	e	 cpf	 ou	 cnpj do	 cliente. Se	a	 conta	 não	existir o	
código fornecido uma	mensagem	deve	ser	impressa.

•  Faça	uma	 função	que	dado	um	número	de	agência,	imprima	todos	os	dados	dos	clientes
com	 os	 nomes começados	 pelas	 letras	 A,	 B	 e	 C	 e	 que	 sejam	 pessoa	 física.	 Se	 não	 existir	 a	
agência	uma	mensagem	deve	ser	impressa.

•  Faça	uma	 função	que	 faça	o	deposito	de	um	certo	valor	numa	conta	corrente	 fornecida.	
Quando	o	deposito	for	feito	faça	a	impressão do	número	da	conta,	do	nome	do	cliente	e	do	novo	
saldo.	(Lembre-se que	o	deposito	aumenta	o	saldo	da	conta).

• 	 Faça	 uma	 função	 que	 execute	 o	 saque	 de	 um	 determinado	 valor	 da	 conta	 corrente	
fornecida.	 Se	 o	 saque	 foi	 possível	 imprima	 todos	 os	 dados	 da	 conta	 e	 se	 não	 for	 possível	
imprima	uma	mensagem	para	o	usuário.

**DESAFIO**:	Defina	uma	nova	estrutura	chamada	nova_conta	que	contenha	os	dados	da	conta	
acrescido	 da	 data	 de	 criação	 da	 conta. Faça	 uma	 função	 que	 dado	 o	 número	 de	 uma	 agência,	
encontre	 todas	 as	 contas	 correntes	 da	 agencia	 que	 tenham	 sido	 abertas	 no	 ano	 a	 partir	 de	
05/2016, tenham	 saldo	 superior	a	R$5000,00	 reais e	 sejam	 pessoa	jurídica	 com	 cnpj	 terminado em 1.



