# Sysboy2000 - Client ESP32

Ce projet représente la partie cliente du système **Sysboy2000**. L'ESP32 récupère les données envoyées par le serveur WebSocket Python et contrôle des composants analogiques (comme un vumètre) pour les afficher en temps réel.

## Fonctionnalités

- Connexion au serveur WebSocket via Wi-Fi pour recevoir des données.
- Configuration Wi-Fi via un portail captif pour entrer les identifiants du réseau.
- Utilisation du DAC de l'ESP32 pour contrôler un vumètre analogique.
- Capacité d'ajouter d'autres composants comme des LED, des boutons ou des écrans.

## Prérequis

- **ESP32** avec support Wi-Fi.
- **Composants matériels** : vumètre analogique, ampli op.
- Bibliothèques PlatformIO et Arduino pour la programmation de l'ESP32.

## Installation

1. **Cloner le projet** :
   git clone https://github.com/utilisateur/sysboy2000-client.git

2. Configurer PlatformIO :
        Ouvrez le projet dans VSCode avec l'extension PlatformIO.
        Assurez-vous que la configuration du Wi-Fi est correcte ou utilisez le portail captif intégré pour la configuration lors du premier démarrage.

3. Téléverser sur l'ESP32 :
        Connectez l'ESP32 à votre ordinateur et téléversez le firmware via PlatformIO.

Utilisation

    Une fois l’ESP32 configuré et connecté au réseau Wi-Fi, il se connectera automatiquement au serveur WebSocket et commencera à afficher les données sur le vumètre.

Extensions futures

    Ajout de nouveaux capteurs ou composants (boutons, écrans OLED).
    Ajustements pour la gestion d'autres types de données que la VRAM.