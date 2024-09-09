import argparse
import json
from os.path import join

def load_config(config_file):
    with open(config_file, "r") as file:
        json_data = json.load(file)
    return json_data


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--config", default="config.json", help="Path to JSON config file in the configs folder")
    args = parser.parse_args()
    config = load_config(args.config)

    test = config.get("test")
    print(test)