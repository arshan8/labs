class bankacc:
    def __init__(self,balance=0):
        self.balance = balance
    def withdraw(self,amount):
        if self.balance>amount and amount>0:
            self.balance-=amount
            print(f"{amount} withdrawed")
        else:
            print("insufficient balance")
    def deposit(self,amount):
        self.balance+=amount
    def show_balance(self):
        print(f"balance is {self.balance}")

def main():
    n = int(input("enetr initial balance:"))
    account = bankacc(n)
    account.show_balance()
    account.withdraw(500)
    account.show_balance()
    account.deposit(500)
    account.show_balance()

main()


