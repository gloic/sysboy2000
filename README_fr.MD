# Sysboy2000

**Sysboy2000** est un projet visant à créer un appareil physique capable d'afficher en temps réel des données issues d'un ordinateur. Cet appareil, contrôlé par un ESP32, utilise une connexion Wi-Fi et communique avec un serveur Python via le protocole WebSocket. L’objectif initial est de contrôler un vumètre analogique pour afficher l’utilisation de la VRAM de la carte graphique.

## Fonctionnalités

- Affichage en temps réel des données d'un PC sur un vumètre analogique.
- Communication bi-directionnelle entre un serveur Python et un ESP32 via WebSocket.
- Configuration Wi-Fi simplifiée via un portail captif sur l'ESP32.
- Extensible à d'autres types de données et composants matériels (LED, boutons, écrans, etc.).

## Architecture du projet

Le projet est divisé en deux parties :

1. **Partie Serveur (PC)** :
   - Serveur WebSocket écrit en Python.
   - Récupère les données système (comme l'utilisation de la VRAM) et les envoie à l'ESP32.

2. **Partie Client (ESP32)** :
   - Client WebSocket sur un ESP32 connecté en Wi-Fi.
   - Contrôle un vumètre analogique via un DAC pour afficher les données reçues.

## Prérequis

- Un ESP32 avec connexion Wi-Fi.
- Un PC avec Python 3.x installé.
- Connexion réseau Wi-Fi pour la communication.
- Composants matériels : vumètre analogique, ampli op, etc.

## Installation

### Serveur

Voir le [README Serveur](./serveur/README.md).

### Client

Voir le [README Client](./client/README.md).

## Extensions futures

Le projet est conçu pour être facilement extensible, permettant l’ajout de nouveaux capteurs, de nouveaux types de données à afficher ou de nouvelles interfaces utilisateur (LED, écran OLED, etc.).
