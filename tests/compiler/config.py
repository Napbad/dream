import os

import yaml



current_dir = os.path.dirname(os.path.abspath(__file__))

project_root = os.path.abspath(os.path.join(current_dir, '..', '..'))

CONFIG_FILE_PATH = os.path.join(project_root, 'config.yml')
def parse_config():
    with open(CONFIG_FILE_PATH, 'r', encoding='utf-8') as file:
        config_data = yaml.safe_load(file)
    return config_data

def print_config(config_data):
    print("Config:", config_data)


config = parse_config()
