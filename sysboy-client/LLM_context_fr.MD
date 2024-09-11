Projet "Sysboy2000" - Contexte détaillé

L'objectif de "Sysboy2000" est de concevoir un appareil physique capable d'afficher en temps réel des données provenant d'un ordinateur. Cet appareil, placé sur mon bureau, sera contrôlé par un ESP32 et connecté en Wi-Fi à mon PC via un protocole WebSocket. Le premier cas d'utilisation sera de piloter un vumètre analogique (en milliampères) pour visualiser l'utilisation de la mémoire VRAM de ma carte graphique.
Structure générale du projet
Parties distinctes :

    Partie serveur (PC) :
        Le serveur sera un script Python exécuté sur l'ordinateur. Il aura deux fonctions principales :
            Récupérer des données en temps réel depuis le PC (comme l’utilisation de la VRAM) à intervalles réguliers.
            Envoyer ces données à l'ESP32 (le client) via un protocole WebSocket.
            Le serveur pourra également recevoir des commandes de l'ESP32, permettant une communication bi-directionnelle.
    Partie cliente (ESP32) :
        Le client sera un ESP32 connecté à divers composants électroniques (boutons, vumètre, LED, etc.).
        L'ESP32 se connectera au serveur Python en Wi-Fi via WebSocket pour recevoir des données à afficher.
        Il contrôlera le vumètre analogique en ajustant le signal envoyé à travers un DAC (convertisseur numérique-analogique) pour commander un ampli op (amplificateur opérationnel) qui pilotera le vumètre.

Choix techniques :

    Protocole de communication : WebSocket :
        Nous avons opté pour WebSocket plutôt que REST, car ce protocole est mieux adapté aux communications en temps réel et bi-directionnelles. Contrairement à REST, WebSocket maintient une connexion ouverte entre le serveur et le client, permettant l'envoi et la réception de données en continu sans avoir à multiplier les requêtes HTTP.
        Cela permettra au PC d’envoyer les informations d’utilisation de la VRAM en temps réel, et à l'ESP32 de les traiter immédiatement pour afficher la valeur sur le vumètre.

    Connexion sans fil : Wi-Fi :
        Le choix du Wi-Fi offre une connexion plus robuste et flexible par rapport à Bluetooth, surtout dans un contexte où les données doivent être envoyées de manière régulière.
        Pour faciliter la connexion de l'ESP32 au réseau Wi-Fi local, l’ESP32 sera initialement configuré en mode Access Point (AP) avec un portail captif. Ce portail permettra d'entrer les identifiants du réseau Wi-Fi via une interface web simplifiée. L'ESP32 pourra ensuite se connecter au réseau et au serveur Python en mode client Wi-Fi.

    Alimentation et communication :
        L'ESP32 sera alimenté en USB depuis l’ordinateur. Cette approche simplifie l’alimentation sans nécessiter de source d'énergie externe, d'autant plus que l’appareil reste sur le bureau et n’a pas besoin d’être éloigné du PC.
        Bien que le Wi-Fi soit utilisé pour la communication, l’USB pourrait également être exploité pour le débogage ou des mises à jour firmware.

    Fréquence des mises à jour :
        La communication entre le serveur et l’ESP32 n'a pas besoin d'être en temps réel précis. Une mise à jour toutes les quelques secondes sera suffisante pour l'affichage des données sur le vumètre.
        Cette fréquence pourra être ajustée plus tard pour optimiser les performances ou adapter l'affichage à d'autres types de données.

Composants électroniques :

    ESP32 :
        Le microcontrôleur ESP32 sera utilisé pour sa capacité à se connecter en Wi-Fi, à gérer des interfaces analogiques/digitales et à consommer peu d'énergie.
        Il communiquera via WebSocket pour recevoir les données et utilisera ses capacités DAC pour contrôler des composants comme le vumètre.
        L’ESP32 pourra également être étendu pour intégrer d’autres composants comme des boutons, potentiomètres, LED, etc.

    Vumètre (en milliampères) :
        Le vumètre analogique sera le premier composant à contrôler. L’ESP32 utilisera son DAC pour générer un signal analogique correspondant à la valeur de la VRAM reçue depuis le PC, avec un ampli op pour ajuster le signal aux besoins du vumètre.
        Cela permettra d’avoir une représentation physique et visuelle de l’utilisation de la mémoire VRAM en temps réel.

Données à afficher :

    VRAM Usage :
        Le premier type de données à afficher sera l’utilisation de la VRAM du PC. Un script Python sur le serveur récupérera cette information via des librairies comme pyNVML (pour les cartes Nvidia) ou psutil pour d’autres types de données si nécessaire.
        L’information sera envoyée sous la forme d’un JSON via WebSocket. Par exemple :

        json

        {
          "type": "vram",
          "value": 60.5
        }

        Le champ value correspond au pourcentage d’utilisation de la VRAM, qui sera converti en une valeur analogique par l’ESP32 pour contrôler le vumètre.

Extensions futures :

    Une fois le projet de base fonctionnel (affichage de la VRAM sur le vumètre), il sera facile d'étendre les fonctionnalités en ajoutant d'autres types de données (CPU, RAM, réseau, etc.) ou des composants supplémentaires comme des LED, des boutons ou même des écrans OLED.
    La structure de communication via WebSocket et le JSON permettent de facilement rajouter des nouvelles informations à afficher sans avoir à refondre l'architecture du projet.
    L'idée est de garder le projet modulaire pour éviter de s’éparpiller, mais d’avoir toujours la possibilité d'ajouter de nouvelles fonctionnalités plus tard.

Plan d’action :

    Implémentation du WebSocket :
        Créer un serveur WebSocket en Python pour récupérer et envoyer les données de la VRAM.
        Implémenter le client WebSocket sur l’ESP32 pour recevoir ces données.

    Wi-Fi et configuration réseau :
        Configurer l’ESP32 pour démarrer en mode Access Point avec un portail captif pour entrer les informations Wi-Fi, puis se connecter au réseau local.

    DAC et vumètre :
        Piloter le vumètre via le DAC de l’ESP32 et l'amplificateur opérationnel pour afficher les données envoyées par le serveur WebSocket.

Avec cette description détaillée, tu as une vue complète de la direction à prendre pour le projet "Sysboy2000", ainsi que les choix techniques concernant la communication, la structure des données, et les composants matériels.