# Sysboy2000 - Serveur

Ce projet constitue la partie serveur de **Sysboy2000**. Il s'agit d'un serveur WebSocket écrit en Python qui récupère des données système comme l'utilisation de la VRAM et les envoie à l'ESP32 pour affichage.

## Fonctionnalités

- Serveur WebSocket en Python.
- Envoi de l'utilisation de la VRAM à l'ESP32 à intervalles réguliers.
- Extensible pour l'envoi d'autres données système (CPU, RAM, réseau, etc.).

## Prérequis

- **Python 3.x** installé sur le PC.
- Bibliothèques Python nécessaires : `websockets`, `psutil`, `pyNVML` (ou autres pour la gestion des ressources système).
  
## Installation

1. **Cloner le projet** :
   git clone https://github.com/utilisateur/sysboy2000-serveur.git

2. Installer les dépendances :
    pip install -r requirements.txt

3. Configurer le serveur :
        Assurez-vous que les librairies pour récupérer les données système sont bien installées (pyNVML pour les cartes Nvidia, par exemple).
        Ajustez les paramètres de connexion WebSocket si nécessaire.

Utilisation

Lancez le serveur WebSocket :

python serveur.py

Le serveur commencera à récupérer les données système et à les envoyer à l'ESP32 connecté.
Extensions futures

    Ajout de nouvelles données système à surveiller (CPU, RAM, utilisation du réseau).
    Mise en place d'une interface web pour configurer le serveur ou visualiser les données.