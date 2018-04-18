import random

#Import the civs into a list, runs at execution
def import_civs():
    civs = ["Babylon","Egypt","England","Ethiopia","Inca","Korea","Persia","Poland","Arabia","Aztec","China","Greece","Huns","Maya","Russia","Shoshone","Spain","Brazil","Byzantium","Celts","Germany","India","Indonesia","Mongolia","Morocco","Ottomans","Portugal","Rome","Sweden","Zulu","America","Assyria","Austria","Carthage","Denmark","Netherlands","France","Japan","Polynesia","Venice","Iroquois"]
    return civs

#Get a singular sudden death civ
def sudden_death_civ(civs):
    print('')
    option = input('Would you like a sudden death civ? Y/N  > ')
    print('')

    if option == 'N' or option == 'n':
        exit()

    else:
        if len(civs) > 0:
            civ_num = random.randint(0,(len(civs)-1))
            print('Sudden death civ:',civs[civ_num])
            civs.pop(civ_num)
            sudden_death_civ(civs)
        else:
            print('There are not enough civs left for this. Sorry')
            return

#List all of the remaining civs
def list_civs(civs):
    print('')
    print(len(civs),'civs remaining.')
    print('')
    for i in range(0,len(civs)-1):
        print(civs[i])
    print('')
    return

#Get the appropriate civs for game
def get_civs(civs):
    print('')
    players = input('Enter the number of players: ')
    civs_per_player = input('Enter the number of civs per player: ')

    #Check to make sure the inputs are valid numbers
    if players.isdigit() == False or civs_per_player.isdigit == False:
        print('Both inputs were not valid numbers. Please try again.')
        get_civs(civs)

    players = int(players)
    civs_per_player = int(civs_per_player)

    #Check to make sure there are enough civs for the options
    if (players*civs_per_player) > len(civs):
        print('That is too many players/civs per player. Please try again.')
        get_civs(civs)

    print('--------------------------------------')
    #Loop through all of the players
    for i in range(0,players):
        print('Player',str(i+1)+'s','Civs')
        #Loop through all of the civs
        for j in range(0,civs_per_player):
            #Get a random civs
            civ_num = random.randint(0,(len(civs)-1))
            print(civs[civ_num])
            civs.pop(civ_num)
        print('--------------------------------------')

    #Call the sudden death civ function
    sudden_death_civ(civs)
    return

#Ban a civ from the list (num = 1 if print, else 0)
def ban_civ(civs, num, option):
    if(num == 1):
        print('')
        print('Which civ would you like to ban?')
        option = input("> ")

    for i in range(0,len(civs)):
        if option == civs[i]:
            if num == 1:
                print('')
                print(civs[i],'was banned.')
            civs.pop(i)
            return civs
    if num == 1:
        print('')
        print(option,'could not be banned.')
    return civs

#Runs the main menu
def main(civs):

    #Ban the base civs
    civs = ban_civ(civs, 0, "Venice")
    civs = ban_civ(civs, 0, "Polynesia")
    civs = ban_civ(civs, 0, "Songhai")
    civs = ban_civ(civs, 0, "Germany")

    #Print out the menu options
    print('')
    print('###### MENU ######')
    print('1. List the remaining civs')
    print('2. Get civs')
    print('3. Ban a civ')
    print('4. Exit')
    print('')

    #Gets user input (1 through 4)
    option = input("> ")

    #Check to make sure the input is a valid number
    if option.isdigit() == False:
        print('Input was not a valid number, please try again.')
        main(civs)

    option = int(option)

    if option == 1:
        list_civs(civs)
        main(civs)

    elif option == 2:
        get_civs(civs)
        return

    elif option == 3:
        civs = ban_civ(civs, 1, '')
        main(civs)

    elif option == 4:
        return


main(import_civs())

