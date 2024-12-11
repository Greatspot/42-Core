<details>
  <summary>English Version</summary>
  <p>This is the English version of the documentation.</p>

# 🖥️ ABOUT Born2beroot

This system administration project focuses on setting up a secure virtual machine. It covers key topics such as virtualization, partitioning, LVM, command-line tools, SSH, and system security measures like sudo, firewalls, and password policies. The project repository includes a script for automated tasks and the virtual machine signature.

### - 💡 Acknowledgments and Born2beroot project tutorial 🖥

I was able to complete this project by following the [gemartin99's Born2beroot-Tutorial](https://github.com/gemartin99/Born2beroot-Tutorial/blob/main/README_EN.md).

## Debian Version
In my project I used Debian 12.8.0 If you want to use the same version, follow the download link: https://cdimage.debian.org/cdimage/release/12.8.0/amd64/iso-cd/debian-12.8.0-amd64-netinst.iso


## Last Checks
Before submitting the project, we performed some checks to ensure everything was set up correctly. These checks included verifying the Linux release, checking the partitions, verifying sudo installation, checking the hostname, checking password policies, checking UFW and SSH status, checking sudo logs, and verifying user group memberships.

```bash
lsb_release -a || cat /etc/os-release
lsblk
dpkg -l | grep sudo
hostnamectl
sudo chage -l username
sudo ufw status numbered
sudo systemctl status ssh
cd /var/log/sudo/sudo.log && cat sudo.log
getent group sudo
getent group user42
cd /usr/local/bin && bash monitoring.sh
```

After that we will turn off the VM, take a snapshot to keep the instance and generate a signature.txt get with the shasum of vdi.

```bash
sudo shutdown now
shasum born2beroot.vdi
cat > signature.txt
```
# ⚙️ How to Test Born2beroot ✅

## Checklist and commands during the evaluation
- [ ] Check if sha1sum of vdi file is equal to signature.txt ```shasum born2beroot.vdi```
- [ ] Check linux release `lsb_release -a || cat /etc/os-release`
- [ ] Check the partitions `lsblk`
- [ ] Check if sudo in on `dpkg -l | grep sudo`
- [ ] Check the hostname `hostnamectl`
- [ ] Check the password policy `sudo chage -l username`
- [ ] Check UFW `sudo ufw status numbered`
- [ ] Check SSH `sudo systemctl status ssh`
- [ ] Check sudo log `cd /var/log/sudo/` then `cat sudo.log`
- [ ] Check if user is on sudo `getent group sudo`
- [ ] Check if user is on user42 `getent group user42`
- [ ] Run monitoring `cd /usr/local/bin` then `bash monitoring.sh`
- [ ] Create a new user `sudo adduser username`
- [ ] Check the username `cd /etc/passwd | grep username`
- [ ] Create a new group `sudo groupadd evaluating`
- [ ] Add the user to new group `sudo adduser username evaluating`
- [ ] Add the user to sudo `sudo adduser username sudo`
- [ ] Check the changes `getent group evaluating` and `getent group evaluating`
- [ ] Change the hostname `sudo hostnamectl set-hostname newname` && `sudo nano /etc/hosts`
- [ ] reboot, see and see the change `sudo reboot` then `hostnamectl`
- [ ] Restore the original hostname `sudo hostnamectl set-hostname oldname` && `sudo nano /etc/hosts`
- [ ] Add the 8080 port `sudo ufw allow 8080`
- [ ] See the changes `sudo ufw status numbered`
- [ ] Delete the port added `sudo ufw delete 1-9`
- [ ] Check the ip address `sudo ip address`
- [ ] Connect to new user `ssh new_user@hostip.0.0.0 -p 4242`
- [ ] Try to connect to root (Must be fail) `ssh root@hostip.0.0.0 -p 4242` 
- [ ] Change time to 1min `sudo crontab -u root -e `


## - Born2beroot Evaluation commands

[gemartin99's Born2beroot Evaluation commands](https://github.com/gemartin99/Born2beroot-Tutorial/blob/main/README_EN.md#9-2-evaluation-commands-%EF%B8%8F).


## - Born2beroot Correction sheet

[gemartin99's Born2beroot Correction sheet](https://github.com/gemartin99/Born2beroot-Tutorial/blob/main/README_EN.md#9--correction-sheet-).



# Born2beroot Tester ✅

<img width="440" alt="Screen Shot 2023-03-09 at 3 40 54 AM" src="https://user-images.githubusercontent.com/66915274/223902066-f2f6a059-9df8-4e32-a92a-14c43ff8fb0f.png">

## How to use 🛠

In order to clone the repository and use the script we will have to install git on our virtual machine. We update the list of packages on the system.


```sudo apt-get update```

Once we have updated, we install the git package with the following command.

```sudo apt-get install git```

Clone this repository in your Debian virtual machine.

```git clone https://github.com/gemartin99/Born2beroot-Tester.git```

Access to the repository.

```cd Born2beroot-Tester/```

Run the script.

```bash Test.sh```


## Questions

### What is a VM and why is it important?
A VM is a virtual machine that allows multiple machines and operating systems to be installed on a single computer. It is important for conducting different tests on both hardware and software.

### What is the difference between CentOS and Debian?
Debian is more user-friendly, while CentOS is more focused on enterprise usage.

### Why did you choose Debian?
I followed the instructions from the recommended system PDF.

### What are Apt, Aptitude, and Apparmor?
Apt and aptitude are advanced package tools for installing and managing programs. Apt only does exactly what is passed on the command line, while aptitude has better autonomous management. Apparmor protects the system by creating security profiles for each program, restricting access to unused system resources.

### What is LVM?
LVM dynamically manages partitions by creating a group for partitions, allocating space dynamically, and avoiding the need for physical disk formatting when reallocating space.

### What is UFW?
UFW allows for simple configuration of the firewall.

### What is SSH?
SSH is a communication encryption technique between host and client. The communication is protected on both ends.

### What is Cron?
Cron allows for scheduling of programs or scripts to run at a specific time.
</details>

<details>
  <summary>Portuguese Version</summary>
  <p>Esta é a versão em Português da documentação.</p>
  
# 🖥️ SOBRE O Born2beroot

Este projeto de administração de sistemas centra-se na configuração de uma máquina virtual segura. Abrange tópicos importantes como virtualização, particionamento, LVM, ferramentas de linha de comando, SSH e medidas de segurança do sistema como sudo, firewalls e políticas de senha. O repositório do projeto inclui um script para tarefas automatizadas e a assinatura da máquina virtual.

### 💡 Agradecimentos e tutorial do projeto Born2beroot 🖥

Consegui completar este projeto seguindo o [gemartin99's Born2beroot-Tutorial](https://github.com/gemartin99/Born2beroot-Tutorial/blob/main/README_EN.md).

## Versão Debian
No meu projeto usei a Debian 12.8.0 Se quiserem usar a mesma versão, sigam o link de download: https://cdimage.debian.org/cdimage/release/12.8.0/amd64/iso-cd/debian-12.8.0-amd64-netinst.iso


## Últimas verificações
Antes de submeter o projeto, fizemos algumas verificações para garantir que tudo estava configurado corretamente. Estas verificações incluíram verificar a versão do Linux, verificar as partições, verificar a instalação do sudo, verificar o nome do host, verificar as políticas de senha, verificar o estado do UFW e do SSH, verificar os logs do sudo e verificar os membros dos grupos de utilizadores.

```bash
lsb_release -a || cat /etc/os-release
lsblk
dpkg -l | grep sudo
hostnamectl
sudo chage -l username
sudo ufw status numbered
sudo systemctl status ssh
cd /var/log/sudo/sudo.log && cat sudo.log
getent group sudo
getent group user42
cd /usr/local/bin && bash monitoring.sh
```

Depois disso vamos desligar a VM, tirar um snapshot para manter a instância e gerar um signature.txt get com o shasum do vdi.

```bash
sudo shutdown now
shasum born2beroot.vdi
cat > signature.txt
```
# ⚙️ Como testar o Born2beroot ✅

## Lista de verificação e comandos durante a avaliação
- Verificar se o sha1sum do ficheiro vdi é igual a signature.txt ```shasum born2beroot.vdi```
- [ ] Verificar a versão do linux `lsb_release -a || cat /etc/os-release`
- [ ] Verificar as partições `lsblk`
- [ ] Verificar se o sudo está ativo `dpkg -l | grep sudo`
- [ ] Verificar o nome do host `hostnamectl`
- [ ] Verificar a política de senhas `sudo chage -l username`
- [ ] Verificar UFW `sudo ufw status numbered`
- [ ] Verificar SSH `sudo systemctl status ssh`
- [ ] Verificar log do sudo `cd /var/log/sudo/` then `cat sudo.log`
- [ ] Verificar se o utilizador está no sudo `getent group sudo`
- [ ] Verificar se o utilizador está em user42 `getent group user42`
- [ ] Executar monitorização `cd /usr/local/bin` then `bash monitoring.sh`
- [ ] Criar um novo utilizador `sudo adduser username`
- [ ] Verificar o nome de utilizador `cd /etc/passwd | grep username`
- [ ] Criar um novo grupo `sudo groupadd evaluating`
- [ ] Adicionar o utilizador ao novo grupo `sudo adduser username evaluating`
- [ ] Adicionar o utilizador ao sudo `sudo adduser username sudo`
- [ ] Verificar as alterações `getent group evaluating` e `getent group evaluating`
- [ ] Alterar o nome da máquina `sudo hostnamectl set-hostname newname` && `sudo nano /etc/hosts`
- [ ] reiniciar, ver e ver a mudança `sudo reboot` então `hostnamectl`
- [ ] Restaurar o hostname original `sudo hostnamectl set-hostname oldname` && `sudo nano /etc/hosts`
- [ ] Adicionar a porta 8080 `sudo ufw allow 8080`
- [ ] Ver as alterações `sudo ufw status numbered`
- [ ] Apagar a porta adicionada `sudo ufw delete 1-9`
- [ ] Verificar o endereço ip `sudo ip address`
- [ ] Conectar ao novo usuário `ssh new_user@hostip.0.0.0 -p 4242`
- [ ] Tentar conectar ao root (Deve falhar) `ssh root@hostip.0.0.0 -p 4242` 
- [ ] Alterar o tempo para 1min `sudo crontab -u root -e `


## - Born2beroot Comandos de avaliação

[comandos de avaliação do Born2beroot de gemartin99](https://github.com/gemartin99/Born2beroot-Tutorial/blob/main/README_EN.md#9-2-evaluation-commands-%EF%B8%8F).


## - Folha de correção do Born2beroot

[folha de correção do Born2beroot de gemartin99](https://github.com/gemartin99/Born2beroot-Tutorial/blob/main/README_EN.md#9--correction-sheet-).



# Born2beroot Tester ✅

<img width="440" alt="Screen Shot 2023-03-09 at 3 40 54 AM" src="https://user-images.githubusercontent.com/66915274/223902066-f2f6a059-9df8-4e32-a92a-14c43ff8fb0f.png">

## Como utilizar 🛠

Para clonar o repositório e usar o script, teremos que instalar o git em nossa máquina virtual. Atualizamos a lista de pacotes do sistema.


```sudo apt-get update```

Depois de atualizado, instalamos o pacote git com o seguinte comando.

```sudo apt-get install git```

Clone este repositório na sua máquina virtual Debian.

```git clone https://github.com/gemartin99/Born2beroot-Tester.git```

Acesso ao repositório.

```cd Born2beroot-Tester/```

Executar o script.

```bash Teste.sh```


## Perguntas

### O que é uma VM e por que ela é importante?
Uma VM é uma máquina virtual que permite que várias máquinas e sistemas operativos sejam instalados num único computador. Ela é importante para a realização de diferentes testes tanto de hardware quanto de software.

### Qual é a diferença entre CentOS e Debian?
O Debian é mais fácil de usar, enquanto o CentOS é mais focado no uso corporativo.

### Por que você escolheu o Debian?
Eu segui as instruções do PDF do sistema recomendado.

### O que são Apt, Aptitude e Apparmor?
Apt e aptitude são ferramentas avançadas de pacotes para instalar e gerenciar programas. O Apt só faz exatamente o que é passado na linha de comando, enquanto o aptitude tem uma melhor gestão autónoma. O Apparmor protege o sistema criando perfis de segurança para cada programa, restringindo o acesso a recursos não utilizados do sistema.

### O que é LVM?
O LVM gerencia dinamicamente as partições criando um grupo para as partições, alocando espaço dinamicamente e evitando a necessidade de formatação do disco físico ao realocar espaço.

### O que é UFW?
O UFW permite a configuração simples do firewall.

### O que é SSH?
O SSH é uma técnica de encriptação da comunicação entre o anfitrião e o cliente. A comunicação é protegida em ambas as extremidades.

### O que é o Cron?
O Cron permite o agendamento de programas ou scripts para serem executados em um horário específico.  
  
</details>