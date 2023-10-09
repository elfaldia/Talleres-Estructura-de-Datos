TALLER 1

-> Lineas para compilar el programa:
cd "Taller 1"
g++ main.cpp -o salida
./salida

-> Usuarias con los cuales esta poblada el sistema: 

    Admin(nombre de usuario, contraseña, correo)

    new Admin("elfaldia","da280855","elfaldia@ml.com");

    Child(nombre de usuario, contraseña, edad)

    new Child("ian","warhammer35",10);
    new Child("siziyi","pandeazucar",4);
    new Child("kleytez","kidvoodoo",7);
    new Child("etoile","fletoile",16);

    Normal (nombre de usuario, contraseña,edad, correo)

    new Normal("lorena","ema",23,"lorena@ml.com");
    new Normal("ronny","aki",19,"ronny@ml.com");
    new Normal("andrea","natacion12",20,"andrea@ml.com");
    new Normal("unflojo","ilovediablo",44,"unflojo@ml.com");
    new Normal("clerigo","darksouls",28,"clerigo@ml.com");
    new Normal("piromantico","fuego",39,"piromantico@ml.com");
    new Normal("carnicero","chanchos",33,"carnicero@ml.com");
    new Normal("rob","talcabelike",32,"rob@ml.com");
    new Normal("uchigatana","bestbuild",20,"uchigatana@ml.com");
    new Normal("claymore","fistbuild",50,"claymore@ml.com");   

-> Softwares con los cuales la base de datos esta poblada:

    Games(nombre,desarrollador,restricción de edad,precio,genero)

    new Games("Dark souls","fromsoftware","+18",36,"RPG");
    new Games("Bloodborne","fromsoftware","+18",38,"RPG");
    new Games("Red dead redemption","Rockstar Games","+18",60,"mundo abierto");
    new Games("Red dead redemption II","Rockstar Games","+18",74,"mundo abierto");
    new Games("Call of duty","Activision","+18",50,"FPS");
    new Games("Fortnite","Epic games","+14",5,"FPS");
    new Games("Apex legends","Electronic Arts","+16",10,"Battle royale");
    new Games("Pubg","Bluehole","+12",60,"Battle royale");
    new Games("World of Warcraft","Blizzard Entertainment","+10",25,"MMO");
    new Games("Albion online","Sandbox Interactive","+10",9,"MMO");
    new Games("FIFA 23","Electronic Arts","+10",90,"Deportes");
    new Games("NBA 2k21","Visuals concepts","+12",51,"Deportes");
    new Games("Uncharted 4","Naughty Dog","+14",37,"Puzzle");
    new Games("The Last of Us","Naughty Dog","+16",41,"Puzzle");
    new Games("Tom Clancy's Rainbow Six: Siege","Ubisoft Montreal","+12",16,"Tactical shooter");
    new Games("Counter-Strike: Global Offensive","Jess Cliffe","+14",8,"Tactical shooter");
    new Games("StarCraft II: Wings of Liberty","Blizzard Entertainment","+10",47,"Strategy");
    new Games("Age of Empires IV","Relic Entertainment","+10",29,"Strategy");
    new Games("Tekken 7"," Bandai Namco Entertainment","+12",12,"Fight");
    new Games("For Honor","Ubisoft Montreal","+16",32,"Fight");

    Office(nombre,desarrollador,restricción de edad,precio,archivos)

    new Office("Google Drive","uchigatana","+18",20,3);
    new Office("Microsoft Excel","ian","+14",45,9);
    new Office("Dropbox","clerigo","+18",28,4);
    new Office("Microsoft Word","etoile","+10",34,6);
    new Office("Microsoft PowerPoint","siziyi","+14",24,7);

    Production(nombre,desarrollador,restricción de edad,precio,solución)

    new Production("Netflix","Reed Hastings","+18+",4, "streaming");
    new Production("Spotify","Daniel Ek","+18+",6, "musica");
    new Production("Photoshop","Adobe Systems Incorporated","+18+",21, "fotos");
    new Production("Youtube","Neal Mohan","+18+",2, "video");

    Navegator(nombre,desarrollador,restricción de edad,precio)

    new Navegator("Opera GX","Opera Software ASA","+12",24);
    new Navegator("Google","Google corporation","+14",32);

    Security(nombre,desarrollador,restricción de edad,precio,malware)

    new Security("Avast One","Avas inc","0",47,"Ransomware");
    new Security("Avira","Avira inc","0",49,"Spyware");
    new Security("Bitdefender","Bitdefender inc","0",21,"Botnets");
    new Security("Kaspersky Premium","Kaspersky inc","0",32,"rootkits");
    new Security("AVG Ultimate","AVG inc","0",43,"gusanos");
    new Security("Malwarebytes Essential","Malwarebytes Essential inc","0",26,"troyanos");

    Social(nombre,desarrollador,restricción de edad,precio)

    new Social("Instagram","Instagram company","+14",640);
    new Social("WhasApp","Meta","+18",600);