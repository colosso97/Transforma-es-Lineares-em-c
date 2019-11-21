/**
 * Programa
 */
import java.util.Scanner;

public class Programa {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int nProfs;
        int i = 0;

        System.out.print("Digite o numero de professores para cadastrar: ");
        nProfs = s.nextInt();

        Professor[] professor= new Professor[nProfs];
          
        do {
            s.nextLine();
            
            professor[i] = new Professor();
            System.out.println("Cadastro do professor " + (i+1));
            System.out.print("Nome: ");
            professor[i].setNome(s.nextLine());
            System.out.print("Email: ");
            professor[i].setE_mail(s.nextLine());
            System.out.print("Telefone: ");
            professor[i].setNum_tel(s.nextLine());
            System.out.print("Salário: ");
            professor[i].setSalario(s.nextFloat());
            
            while(professor[i].getSalario() == 0) { 
                System.out.print("Salário do professor só pode ser maior do que 960. Tente novamente.\nSalário: ");
                professor[i].setSalario(s.nextFloat());
            } 

            System.out.println("Cadastrado com sucesso!\n");
            i++;
        } while (i < nProfs);

        s.close();
    }
}