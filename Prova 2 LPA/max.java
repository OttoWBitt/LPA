/*
* Nome:Otto Bittencourt - 504654
* 2 Prova de LPA
 */
import java.io.*;
import java.*;
import java.nio.charset.*;
import java.util.Formatter;
import java.util.Scanner;
import java.io.File;
import java.io.UnsupportedEncodingException;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class max {

	static BufferedReader read = null;

	static int[][] matriz;

	public static void main(String[] args) throws Exception {

		read = new BufferedReader(new InputStreamReader(System.in));

		Vector<Integer> vetorPrecoGas;

		String[] spli;

		int cidadesNaRota, numeroDeEstradas, tanque;

		String aux = read.readLine();

		while (!aux.equals("0 0 0")) {

			spli = aux.split(" ");

			cidadesNaRota = Integer.parseInt(spli[0]);
			numeroDeEstradas = Integer.parseInt(spli[1]);
			tanque = Integer.parseInt(spli[2]);

			matriz = new int[cidadesNaRota][cidadesNaRota];

			vetorPrecoGas = new Vector<>(cidadesNaRota);

			aux = read.readLine();

			for (int i = 0; i < numeroDeEstradas; i++ ) {

				spli = aux.split(" ");
				int cidadeA, cidadeB, consumoGas;
				cidadeA = Integer.parseInt(spli[0]);
				cidadeB = Integer.parseInt(spli[1]);
				consumoGas = Integer.parseInt(spli[2]);
				matriz[cidadeA - 1][cidadeB - 1] = consumoGas;
				aux = read.readLine();
			}

			/*

			for (int i = 0; i < matriz.length; i++) {
				for (int j = 0; j < matriz[i].length; j++) {
					System.out.print(matriz[i][j]);
				}
				System.out.println("");
			}

			*/

			for (int j = 0; j < cidadesNaRota ; j++ ) {
				vetorPrecoGas.add(Integer.parseInt(aux));
				aux = read.readLine();
			}

			int comeco = 0;
			int cidadeAtual = 0;
			int custoGas = 0;
			int quantidadeGas = tanque;
			int custoViajem = 0;
			int diferenca = 0;
			boolean sinal = false;

			for (int i = comeco; i < cidadesNaRota ; i++ ) {
				for (int j = 0; j < cidadesNaRota ; j++ ) {
					if (matriz[i][j] != 0) {
						custoGas = matriz[i][j];
						if (custoGas < tanque) {
							if (quantidadeGas > custoGas) {
								cidadeAtual = j;
								quantidadeGas = quantidadeGas - custoGas;
								comeco = j;
								j = cidadesNaRota;
							} 
							else if (quantidadeGas < custoGas) {
								if (custoGas <= tanque) {

									diferenca = Math.abs(custoGas - quantidadeGas);
									custoViajem = (diferenca * (vetorPrecoGas.get(cidadeAtual)));
									cidadeAtual = j;
									quantidadeGas = quantidadeGas - custoGas;
									comeco = j;
									j = cidadesNaRota;
									sinal = true;
								}
							}
						} 
						else if (custoGas > tanque) {
							System.out.println("-1");
							break;
						}
					}
				}
			}
			if (sinal == true) {
				System.out.println(custoViajem);
			}
		}
	}
}