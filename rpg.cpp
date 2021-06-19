#include <ctime>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <list>
#include <vector>

/**
 * Um sistema de RPG em modo text que, dependendo das 
 * escolhas da/do jogadora/or pode mudar o final
 */

struct Personagem
{
		std::string nome;
		unsigned int energia;
		unsigned int altura;
		unsigned int forcaFisica;
		unsigned int forcaMagica;
		unsigned int creditos;
};

float geraAleatorio(){
    return rand() / (float) RAND_MAX;
}

struct Personagem boasVindasDoJogo(){
    std::cout << "Bem vindo ao Hyako Secret Room!\n";
    std::cout << "Voce esta em um mundo onde a ficção é a realidade, \n";
    std::cout << "Com isso o mundo esta sobre ameaça de um ser poderoso chamado Leno Brega\n";
    std::cout << "ele busca migrar o reino de hyako para sua coleção de planetas no sistema solar de bueno...\n";

    std::cout << "nós de hyako secret room somos seres poderosos,porem ainda não podemos contra Leno brega\n";
    std::cout << "Por isso te convocamos aqui neste mundo,sabemos que voce podera nos ajudar...\n";
    std::cout << "Voce é a nossa unica salvação,nos diga quem é voce.\n";

    std::string nome;
    std::cin.ignore();
    std::getline(std::cin, nome);

    std::cout << "De agora em diante lhe chamaremos de Sr."<< nome <<"!\n";

    struct Personagem eu;

 

    eu.nome = nome;
    eu.energia = (geraAleatorio() * 90) + 10;
    eu.altura = geraAleatorio() * 300;
    eu.forcaFisica = geraAleatorio() * 100;
    eu.forcaMagica = geraAleatorio() * 50;
    eu.creditos = 26;

 

    return eu;
}

void mostraStatusDoJogador(struct Personagem &p){

    if(p.energia == 0){
        std::cout << "press f to pay respect" << std::endl;
        return;
    }

    std::cout << "Você agora tem " << p.altura/100.0 <<
                " metros de altura, " << p.energia << " de energia com uma força de intensidade " <<
                p.forcaFisica << " e um poder mágico de " <<
                p.forcaMagica << " orbites $" << p.creditos << std::endl;
}

void faseDaCidade(struct Personagem &p){
    
    unsigned int opcao = 0;

    while(opcao < 1 || opcao > 2){
        std::cout << "voce está no quarto principal do reino, neste quarto voce ve duas portas: Uma porta te levara até a tenda e a outra porta te levara até uma loja de equipamentos.\n Que porta voce escolhera?" << std::endl;
        std::cout << "1-Tenda\n2-Loja de equipamentos" << std::endl;

        std::cin >> opcao;
    }

    if(opcao == 1){
        std::cout << "O vendedor te olha e pergunta: O que deseja meu caro?" << std::endl;
        
        std::cout << "1-Nada\n2-Comida\n3-esferas do dragão" << std::endl;
        std::cin >> opcao;

        if(opcao == 2){

            opcao = 0;

            while(opcao < 1 || opcao > 2){
                std::cout << "1-Bife Acebolado (Dá muita energia)\n2-Banana Frita (Dá pouca energia)" << std::endl;
                std::cin >> opcao;
            }

            switch(opcao){
                case 1:
                    if(p.creditos >= 50){
                        p.energia += 50;
                        p.creditos -= 50;
                    }else{
                        std::cout << "Desculpe mas não posso te vender isso..." << std::endl;
                    }
                    break;
                case 2:
                    if(p.creditos >= 10){
                        p.energia += 10;
                        p.creditos -= 10;
                    }else{
                        std::cout << "Desculpe mas não posso te vender isso..." << std::endl;
                    }
                    break;
            }
            return;

        }else if(opcao == 3){
            std::cout << "Esqueci,elas não estão a venda!!!" << std::endl;
            p.energia = p.energia - p.energia;
            return;
        }else{
            std::cout << "mas que sujeito estranho....";
        }

    }

    if(opcao == 2){
        std::cout << "O vendedor te pergunta: Pronto pra Descer o sarrafo em geral?" << std::endl;
        
        std::cout << "1-Não rapai\n2-kamado nichirin\n3-Death Note" << std::endl;
        std::cin >> opcao;

        if(opcao == 2){

            std::cout << "Você tem bons olhos,porem não tem figuras suficientes inbecil" << std::endl;

            if(p.creditos >= 200){
                std::cout << "Muitos Onis cairão por essa Katana!!" << std::endl;
                p.creditos = p.creditos - 200;

                mostraStatusDoJogador(p);
            }else{
                std::cout << "Você não merece esta Katana,domine sua respiração primeiro!!" << std::endl;
            }

        }else if(opcao == 3){
            std::cout << "Quem diria,agora vou mostrar o novo mundo para Leno Brega!" << std::endl;

            if(p.creditos >= 25){
                std::cout << "Muito bem..." << std::endl;
                p.creditos = p.creditos - 25;

                mostraStatusDoJogador(p);
            }else{
                std::cout << "Vaza daqui Fracote!!!" << std::endl;
            }
        }else{
            std::cout << "MORRA!." << std::endl;
        }
    }
}

void faseDaVeinha(struct Personagem &p){
    
    unsigned int opcao=0;

 

       while(opcao < 1 || opcao > 3){
        std::cout << "ao iniciar sua jornada, saindo de seu vilareijo calmo e pacífico," << std::endl;
        std::cout << "essa é a realidade da grande maioria dos 'herois\n'" << std::endl;
        std::cout << "após se distanciar relativamente de sua terra natal, você encontra um grupo de jovens, cuja aparência se assemelha aos seguidores do rei Demônio\n" << std::endl;
        std::cout << "eles estão espancando uma senhora de aparência duvidosa\n você possui três opções: 1-procurar por ajuda\n 2-ignorar e seguir sua jornada\n 3-mesmo estando em desvantagem e possuir poucas forças, tentar salvar aquela senhora!" << std::endl;
        std::cin >> opcao;
    }

 

    if(opcao == 1){
        
        opcao=0;
        
        std::cout << "uma pequena e humilde vila está ao seu alcance, você corre para lá em procura de um guarda" << std::endl;
        
        std::cout << "ao encontrar um guarda, você explica a ocasião e pede por ajuda " << std::endl;
        std::cout << "ambos saem correndo em direção á idosa e se deparam com uma espantosa cena!!!" << std::endl;
        std::cout << "a idosa que estava sendo espancada, misteriosamente aparece sobre os corpos de todos os seus agressores(aparentemente inconscientes) " << std::endl;
        std::cout << "ao questionar a idosa, ela misteriosamente some e deixa um pacote no chão " << std::endl;
        std::cout << "1-abrir  2-guardar em sua mochila" << std::endl;
        std::cin >> opcao;
        
        if(opcao == 1){
            std::cout << "ao abri-la, você se depara com um misterioso item que te altera de alguma maneira" << std::endl;
            p.energia = p.energia*1.15;
            std::cout <<"você obteve um aumento em sua energia máxima! " << p.energia << std::endl;
        }
        }

 

       if(opcao == 2){

 

          std::cout << "é uma escolha egoísta, porém, segura, sua aventura continua!!!" << std::endl;  

 

       }

 

    if(opcao == 3){
        
        opcao = 0; 
         while(opcao < 1 || opcao > 2){
        std::cout << "após muito apanhar, sua vitória é certa, os agressores recuam e deixam a idosa em paz" << std::endl;
        std::cout << "IDOSA:muito obrigada por sua coragem, jovem, sei que é algo egoísta de minha parte, mas...\n poderia me ajudar a carregar meus pertences até minha moradia? " << std::endl;  
        std::cout << "1-ajuda\n  2-inventa alguma desculpa" << std::endl;
        std::cin >> opcao;
        p.energia = p.energia*0.20;
         }
         
         if (opcao == 1){
             std::cout << "a viagem é longa e cansativa, sua vitória não foi barata, consequentemente sua energia está escassa\n" << std::endl;
             std::cout << "seu sangramento cessa vagarosamente, voce está só o pó!\n " << p.energia << "de vida restante" << std::endl;
             std::cout << "quando chega na 'casa' da senhora, percebe que na verdade é uma pequena cabana no meio de uma floresta\n" << std::endl;
             std::cout << "ao adentrar seus aposentos, a velha senhore lhe cura com estranhos liquidos(aparentemente algo comestivel)\n" << std::endl;
             std::cout << "seu corpo se cura rapidamente e sente-se com novos poderes\n" << std::endl;
             p.energia = p.energia*5;
             std::cout << "a idosa se apresenta, seu nome é Lucy.\n" << std::endl;
             std::cout << "contando sua história, ela diz que seu filho era um bravo guerreiro que morrera lutando bravamente contra o rei demônio\n" << std::endl;
             std::cout << "como recompensa por sua coragem, você recebe o antigo equipamento de seu falecido filho, assim, podendo lutar, equilibradamente contra inimigos poderosos" << std::endl;
             p.energia=p.energia*1.8;
             p.forcaFisica=p.forcaFisica*2.5;
             p.forcaMagica=p.forcaMagica*0.6;
             std::cout << "com a armadura e espada de um bravo guerreiro seus atributos sobem: " << std::endl;
             std::cout << "sua nova força física é " << p.forcaFisica << std::endl;
             std::cout << "com potentes defesas, sua vida máxima é elevada " << p.energia <<  std::endl;
             
         }
         if(opcao== 2){
             std::cout << "após a luta, sua sobrevivência é duvidosa.\n" << std::endl;
             std::cout << "como forma de agradecimento, a senhora retira uma estranha esfera de sua bolsa e diz que será ultil de alguma forma\n" << std::endl;
             std::cout << "sua vida é curada completamente e você recebe equipamentos básicos de um mago, subindo assim, seus atributos\n" << std::endl;
             std::cout << "IDOSA: meu filho foi um bravo guerreiro outrora, infelizmente nao habita entre nós, creio que habilidades de um mago, com ataques a longa distância, seja algo que te ajudará a sobreviver!" << std::endl;
             std::cout << "sua força mágica aumenta: " << p.forcaMagica << std::endl;
             
         }
        
        
        
        
    }
}

void faseGothamCity(struct Personagem &p)
{

	unsigned int opcao = 0;

	while (opcao < 1 || opcao > 2)
	{
		std::cout << "Você chegou em Gotham City, vamos ver se conseguimos arranjar dinheiro para conseguirmos nos preparar melhor. Quem sabe não acabamos encontrando o Batman por aqui!" << std::endl;

		std::cout << "Olhe só, estão contratando temporariamente, pode ser uma boa para conseguirmos uma graninha a mais, o que acha?" << std::endl;

		std::cout << "1 - Claro\n2 - Nah, deixa queto" << std::endl;

		std::cin >> opcao;
	}

	if (opcao == 1)
	{
		std::cout << "Contratante: Olá cidadão de gotham city, você está atras de uma renda extra certo? Bem, venha comigo, estou precisando de um ajudante, é bem rapidinho." << std::endl;
		std::cout << "1 - Vamos la\n2 - To afim não, deu preguiça" << std::endl;

		std::cin >> opcao;

		unsigned int ganho = 0;

		switch (opcao)
		{
			case 1:

				std::cout << "Algum tempo depois..." << std::endl;
				std::cout << "Ufa! Acabamos, obrigado pela ajuda, não sei como eu faria isto sozinho, aqui está seu pagamento" << std::endl;

				ganho = geraAleatorio() * 100;

				p.creditos = p.creditos + ganho;

				p.energia = p.energia - 5;

				std::cout << "+ $" << ganho << std::endl;

				std::cout << "Conseguimos uma graninha a mais agora, podemos juntas para comprarmos comidas e armas, vamos descançar um pouco para recupermos energia após um longo dia de trabalho. E eu juro que vi o Batman em cima de algum predio..." << std::endl;
				break;

			case 2:
				std::cout << "Ah que pena, eu precisava mesmo de ajuda, boa sorte com sua jornada..." << std::endl;
				break;
		}
	}

	if (opcao == 2)
	{
		std::cout << "Ok né, qualquer coisa pedimos emprestado para alguem." << std::endl;
	}
}

void faseDaFloresta(struct Personagem &p)
{

	unsigned int opcao = -1;

	while (opcao < 1 || opcao > 2)
	{
		std::cout << "Heroi... O rei demonio esta esperando por voce na cidade caida Lore! " << std::endl;
		std::cout << "Antes de poder confronta-lo, voce precisara� passar pela floresta obscura e derrotar as criaturas malignas que nela habitam.\n\n";

		std::cout << "Voce esta na entrada da floresta, nessa entrada h� dois estabelecimentos:\n\n1-Centro de treinamento\n2-Magic Shoppe\n3-Nada" << std::endl;
		std::cin >> opcao;

	}

	if (opcao == 1)
	{
		std::cout << "Salve bravo aventureiro! Eu sou mazumi um mago guerreiro." << std::endl;
		std::cout << "Quer aprender as habilidades que posso te ensinar?" << std::endl;
		std::cout << "Muito bem." << std::endl;
		std::cout << "Se voce VIVER durante minhas aulas, voce pode apenas me agradecer!\n" << std::endl;

		std::cout << "1-Mago\n2-Guerreiro\n3-Nada\n\n" << std::endl;
		std::cin >> opcao;

		if (opcao == 1)
		{

			if (p.creditos >= 1)
			{
				std::cout << "Parabéns, voc� adquiriu a Classe Mago, com ela se pode pegar as energias misticas do mundo ao seu redor e enviar fogo e gelo pelo campo de batalha!\n\n" << std::endl;
				p.creditos = p.creditos - 2;

				mostraStatusDoJogador(p);

			} else
			{
				std::cout << "Você não possui créditos o suficiente." << std::endl;
			}

		} else if (opcao == 2)
		{

			if (p.creditos >= 1)
			{
				std::cout << "Parabéns, voc� adquiriu a Classe Guerreiro, com  ela se pode ter um grande engajamento em combates corpo a corpo!\n\n" << std::endl;
				p.creditos = p.creditos - 2;

				mostraStatusDoJogador(p);

			} else
			{
				std::cout << "Você não possui créditos o suficiente." << std::endl;
			}

		} else
		{
			std::cout << "Que cara estranho....";
		}

	}
	//Division
	if (opcao == 2)
	{
		std::cout << "Eu sou o Warlic, bem-vindo a minha loja de magia! Sinta-se a vontade para examinar minha colecao requintada de itens magicos e pocoes." << std::endl;

		std::cout << "1-Nada\n2-Poc�es\n3-Armamento" << std::endl;
		std::cin >> opcao;

		if (opcao == 2)
		{

			opcao = 0;

			while (opcao < 1 || opcao > 2)
			{
				std::cout << "1-Po��o f�sica (Aumenta forca)\n2-Po��o magia (Aumenta a forca magica)" << std::endl;
				std::cin >> opcao;
			}

			switch (opcao)
			{
				case 1:
					if (p.creditos >= 2)
					{
						p.forcaFisica += 10;
						p.creditos -= 2;
					} else
					{
						std::cout << "Desculpe mas não posso te vender isso..." << std::endl;
					}
					break;
				case 2:
					if (p.creditos >= 1)
					{
						p.forcaMagica += 10;
						p.creditos -= 1;
					} else
					{
						std::cout << "Desculpe mas não posso te vender isso..." << std::endl;
					}
					break;
			}
			return;

		} else if (opcao == 3)
		{
			opcao = 0;

			while (opcao < 1 || opcao > 2)
			{
				std::cout << "1-Holy avenger - Espada m�gica forjada com sangue de deuses, qualquer coisa que estre na frente de seu fio � destruido instantaneamente, sem direito a testes de resist�ncia.\n" << std::endl;
				std::cout << "2-super nova bow - Arco que tem a energia de uma estrela concentrada em s�, suas flechas evapora o que toca.\n";
				std::cin >> opcao;
			}

			switch (opcao)
			{
				case 1:
					std::cout << "Otima escolha guerreiro!\n\n";
					if (p.creditos >= 2)
					{
						p.forcaFisica += 200;
						p.creditos -= 2;
					} else
					{
						std::cout << "Desculpe mas não posso te vender isso..." << std::endl;
					}
					break;
				case 2:
					std::cout << "Otima escolha guerreiro!\n\n";
					if (p.creditos >= 1)
					{
						p.forcaMagica += 200;
						p.creditos -= 1;
					} else
					{
						std::cout << "Desculpe mas não posso te vender isso..." << std::endl;
					}
					break;
			}
			return;
		}
	}

}

void faseBatalha(struct Personagem &p)
{
	unsigned int r, d;

	std::cout << "\nAp�s uma exaustiva caminhada sobre o sol" << std::endl;
	std::cout << "Voce decide descansar aos pes de uma grande arvore.No meio da noite, um barulho vindo da dire��o do mato te faz acordar" << std::endl;
	std::cout << "Com o cora��o acelerado voce avista uma pessoa, na qual esta amea�ando\n" << std::endl;
	std::cout << "O que voce faz?\n1-Batalha\n2-Corre\n3-Conversa\n";
	std::cin >> r;

	if (r == 1)
	{
		std::cout << "Furioso com a situa��o, voce aceita a batalha!!\n" << std::endl;
		std::cout << "Escolha seu movimento\n1-Soco na cara\n2-Chute na barriga\n3-Mordida na orelha" << std::endl;
		std::cin >> d;

		switch (d)
		{

			case 1:
				std::cout << "Seu soco faz cocegas no seu oponente" << std::endl;
				p.energia = -10;

				break;

			case 2:
				std::cout << "\nBela tentativa, mas seu chute foi bloqueado" << std::endl;
				p.energia = -10;

				break;

			case 3:
				std::cout << "Um golpe sujo, mas eficaz" << std::endl;
				std::cout << "Machucado, seu oponente foge da batalha!" << std::endl;
				break;

		}

	}

	if (r == 2)
	{

		std::cout << "Voce escapa daquela situa��o perigosa.Mas provaste que nao tem coragem suficiente para encarar esse mundo!!!" << std::endl;
		p.energia = p.energia - p.energia;

		return;
	}

	if (r == 3)
	{
		std::cout << "Para ele dialogo n�o � uma op��o!\n";

	}
}

void faseDaCaverna(struct Personagem &p)
{

	unsigned int opcao = 0;

	while (opcao < 1 || opcao > 2)
	{
		std::cout << "Voc� chegou na floresta e possui duas cavernas. Tem que decidir em qual entrar." << std::endl;
		std::cout << "1-Caverna Verde\n2-Caverna Azul" << std::endl;

		std::cin >> opcao;
	}

	if (opcao == 1)
	{
		std::cout << "Quando voc� entra possui dois ba�s e precisa escolher apenas uma." << std::endl;

		std::cout << "1-Detona\n2-Fraco\n3-Nenhum Ba�" << std::endl;
		std::cin >> opcao;

		if (opcao == 2)
		{

			opcao = 0;

			while (opcao < 1 || opcao > 2)
			{
				std::cout << "1-Machado voc� possuir� maior resistencia\n2-Lan�a voc� ter� um ataque potenteroso." << std::endl;
				std::cin >> opcao;
			}

			switch (opcao)
			{
				case 1:
					if (p.creditos >= 10)
					{
						p.energia += 30;
						p.creditos -= 10;
					} else
					{
						std::cout << "Desculpe mas necessita de mais cr�ditos." << std::endl;
					}
					break;
				case 2:
					if (p.creditos >= 10)
					{
						p.energia += 10;
						p.creditos -= 10;
					} else
					{
						std::cout << "Desculpe mas necessita de mais cr�ditos." << std::endl;
					}
					break;
			}
			return;

		} else if (opcao == 3)
		{
			std::cout << "Toma vergonha e escolha algo." << std::endl;
			p.energia = p.energia - p.energia;
			return;
		} else
		{
			std::cout << "Volte quando souber o que deseja.";
		}

	}

	if (opcao == 2)
	{
		std::cout << "Quando voc� entra possui dois ba�s e precisa escolher apenas uma." << std::endl;

		std::cout << "1-Fino Trato\n2-Gostosura\n3-Nenhum Ba�" << std::endl;
		std::cin >> opcao;

		if (opcao == 2)
		{

			opcao = 0;

			while (opcao < 1 || opcao > 2)
			{
				std::cout << "1-Faca voc� possuir� maior resistencia\n2-Porrete voc� ter� um ataque potenteroso." << std::endl;
				std::cin >> opcao;
			}

			switch (opcao)
			{
				case 1:
					if (p.creditos >= 10)
					{
						p.energia += 30;
						p.creditos -= 10;
					} else
					{
						std::cout << "Desculpe mas necessita de mais cr�ditos." << std::endl;
					}
					break;
				case 2:
					if (p.creditos >= 10)
					{
						p.energia += 10;
						p.creditos -= 10;
					} else
					{
						std::cout << "Desculpe mas necessita de mais cr�ditos." << std::endl;
					}
					break;
			}
			return;

		} else if (opcao == 3)
		{
			std::cout << "Toma vergonha e escolha algo." << std::endl;
			p.energia = p.energia - p.energia;
			return;
		} else
		{
			std::cout << "Volte quando souber o que deseja.";
		}
	}
}
//Fase Labirinto

std::vector<std::string> RemoverOpcao(char opcao, std::vector<std::string> direcao)
{
	std::vector<std::string> direcao2;
	for (int i = 0; i < direcao.size(); i++)
	{
		if (opcao != direcao[i][0])
		{
			direcao2.push_back(direcao[i]);
		}
	}
	return direcao2;
}

char PerguntarDirecao(std::vector<std::string> direcao)
{

	unsigned char opcao;
	std::cout << "Você pode escolher essas direções\n";
	for (int i = 0; i < direcao.size(); i++)
	{
		std::cout << direcao[i][0] << " - " << direcao[i] + "\n";
	}
	std::cout << "Qual direção você escolhe?\n";
	std::cin >> opcao;
	system("clear||cls");
	return opcao;
}

//Seleciona Direcao
bool escolherDirecao(bool direcaoCorreta, std::list<char> mapa)
{

	if (mapa.front() == 'X')
	{
		return true;
	} else
	{
		std::vector<std::string> direcao;

		direcao.push_back("Frente");
		direcao.push_back("Direita");
		direcao.push_back("Esquerda");

		bool ok = false;
		bool dC = false;

		do
		{
			if (direcaoCorreta)
			{
				do
				{
					switch (PerguntarDirecao(direcao))
					{
						case 'f':
						case 'F':
							direcao = RemoverOpcao('F', direcao);
							std::cout << "\nVocê decidiu seguir em frente! \n\n";
							if (mapa.front() == 'F')
							{
								mapa.pop_front();

								dC = true;
							}
							break;
						case 'd':
						case 'D':
							direcao = RemoverOpcao('D', direcao);
							std::cout << "\nVocê decidiu virar a direita! \n\n";
							if (mapa.front() == 'D')
							{
								mapa.pop_front();

								dC = true;
							}
							break;
						case 'e':
						case 'E':
							direcao = RemoverOpcao('E', direcao);
							std::cout << "\nVocê decidiu virar a esquerda! \n\n";
							if (mapa.front() == 'E')
							{
								mapa.pop_front();

								dC = true;
							}
							break;
						default:
							std::cout << "Direcao não encontrada\n";
							ok = true;
							break;
					}
				} while (ok);
				if (escolherDirecao(dC, mapa))
				{
					return true;
				}

			} else
			{
				do
				{
					switch (PerguntarDirecao(direcao))
					{
						case 'f':
						case 'F':
							direcao = RemoverOpcao('F', direcao);
							std::cout << "\nVocê decidiu seguir em frente! \n\n";
							if (mapa.front() == 'F')
							{
								mapa.pop_front();
							}
							break;
						case 'd':
						case 'D':
							direcao = RemoverOpcao('D', direcao);
							std::cout << "\nVocê decidiu virar a direita! \n\n";
							if (mapa.front() == 'D')
							{
								mapa.pop_front();
							}
							break;
						case 'e':
						case 'E':
							direcao = RemoverOpcao('E', direcao);
							std::cout << "\nVocê decidiu virar a esquerda! \n\n";
							if (mapa.front() == 'E')
							{
								mapa.pop_front();
							}
							break;
						default:
							std::cout << "Direcao não encontrada\n";
							ok = true;
							break;
					}
				} while (ok);;
				int op = geraAleatorio() * 5;

				switch (op)
				{
					case 1:
						std::cout << "Você encontrou o fim desse caminho!\n";
						break;
					case 2:
						std::cout << "Não tem nada aqui!\n\n";
						break;
					case 3:
						std::cout << "Vozes desconhecidas...\n-Esse não é o seu caminho, volte antes que seja tarde demais!\n\n";
						break;
					case 4:
						std::cout << "Caminho sem saída!\n\n";
						break;
					case 5:
						std::cout << "Você andou... e andou... e percebeu que estava andando em círculo...\n\n";
						break;
					default:
						std::cout << "Você encontrou o fim desse caminho!\n\n";
						break;
				}

				if (direcao.size() == 0)
				{
					std::cout << "\nVocê percebeu que olhou todos os caminhos desse lado, então decidiu que deveria voltar e ir por um caminho diferente! \n\n";
					return false;
				} else
				{
					std::cout << "\nVocê voltou para o último ponto, antes de se perder, escolha outro caminho!!!\n\n";
				}
			}
			if (mapa.front() == 'X')
			{
				break;
			}
		} while (true);

	}

}

//Iniciar
void faseLabirinto(struct Personagem &p)
{
	std::list<char> mapa;

	mapa.push_back('F');
	mapa.push_back('F');
	mapa.push_back('D');
	mapa.push_back('E');
	mapa.push_back('X');

	std::cout << "\n\nVocê chegou no labirinto do dragão, aqui vivia o dragão rei, já faz mais de um século que ele morreu, mas até hoje a boatos de quem passa por aqui que o seu coração ainda pulsa, e quem estiver no domínio do coração se tornara o mago mais poderoso de todos, talvez mais poderoso que o próprio Merlin. \n\nPressione qualquer tecla pra continuar...";
	getchar();
	system("clear||cls");
	std::cout << "Você entrou no labirinto...  \n\n";
	if (escolherDirecao(true, mapa))
	{
		std::cout << "Você finalmente encontrou o coração do dragão! \n";
		p.forcaMagica = 60;
	}
}

int main(int argc, char **argv)
{
	// s = seed rand = aleatório
	// std::time vem da biblioteca ctime
	std::srand(std::time(nullptr)); //<-- Retorno o Unix time stamp

	struct Personagem j = boasVindasDoJogo();

	std::cout << "Você recebeu um presente das divindades da terra!\n";
	std::cout << "Lembre-se que nem sempre grandes poderes significam grande honra!\n";

	mostraStatusDoJogador(j);
	std::cout << std::endl << "Cidade" << std::endl;
	faseDaCidade(j);

	mostraStatusDoJogador(j);
	std::cout << std::endl << "Labirinto" << std::endl;
	//faseLabirinto(j);

	mostraStatusDoJogador(j);
	std::cout << std::endl << "Caverna" << std::endl;
	faseDaCaverna(j);

	mostraStatusDoJogador(j);
	std::cout << std::endl << "Batalha" << std::endl;
	faseBatalha(j);

	mostraStatusDoJogador(j);
	std::cout << std::endl << "Floresta" << std::endl;
	faseDaFloresta(j);

	mostraStatusDoJogador(j);
	std::cout << std::endl << "Gothan City" << std::endl;
	faseGothamCity(j);
	
	mostraStatusDoJogador(j);
	std::cout << std::endl << "A velha" << std::endl;
	faseDaVeinha(j);

	mostraStatusDoJogador(j);
}
