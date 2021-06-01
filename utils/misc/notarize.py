# adapted from from https://github.com/najiji/notarizer/blob/master/notarize.py

import argparse
import os
import subprocess
import json
import sys
import time

def log_message(message, newline=True):
    sys.stderr.write(message)
    if newline:
        sys.stderr.write("\n")


def upload_package(args):
    process = subprocess.Popen(['xcrun', 'altool', '--notarize-app', '-t', 'osx',
                                '-f', args.package,
                                '--primary-bundle-id', args.primary_bundle_id,
                                '-u', args.username,
                                '--output-format', 'json', '-p', args.password],
                               stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    log_message('>> Uploading dmg to apple')
    output, error = process.communicate()
    output_str = output.decode('utf-8') + error.decode('utf-8')
    log_message(output_str)
    if not 'No errors uploading' in output_str:
        log_message('[Error] Upload failed')
        exit(1)
    m = json.loads(output_str)
    if 'notarization-upload' in m and 'RequestUUID' in m['notarization-upload']:
        uuid = m['notarization-upload']['RequestUUID']
        log_message('>> Job UUID: %s' % uuid)
        return uuid
    log_message('[Error] No UUID created')
    exit(1)


def check_status(args, uuid):
    process = subprocess.Popen(['xcrun', 'altool', '--notarization-info', uuid,
                                '-u', args.username, '-p', args.password,
                                '--output-format', 'json'],
                               stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    output, error = process.communicate()
    output_str = output.decode('utf-8') + error.decode('utf-8')
    m = json.loads(output_str)
    if 'notarization-info' in m and 'Status' in m['notarization-info']:
        status = m['notarization-info']['Status']
        if 'in progress' in status:
            return True
        elif 'success' in status:
            return False
    log_message(output_str)
    log_message('[Error] Notarization failed')
    exit(1)


def staple(args):
    process = subprocess.Popen(['xcrun', 'stapler', 'staple', args.package],
                               stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    output, error = process.communicate()
    log_message(output.decode('utf-8'))
    log_message(error.decode('utf-8'))


def main():
    parser = argparse.ArgumentParser(description="Notarizes supplied dmg by uploading it to apple servers.")
    parser.add_argument("--package", help="Path to the dmg file", action='store', required=True)
    parser.add_argument("--username", help="Apple ID username to use to notarize", action='store', required=True)
    parser.add_argument("--primary-bundle-id", help="Bundle id of package as specified in Info.plist", action='store', required=True)
    parser.add_argument("--password", action='store', help="Password for the appleid.", required=True)
    args = parser.parse_args()

    if not args.package.endswith('.dmg'):
        log_message('Supplied package %s is not a dmg file - skipping' % args.package)
        exit(0)

    uuid = upload_package(args)

    time.sleep(30)
    while check_status(args, uuid):
        log_message('.. Notarization in progress. Checking back in 30s')
        time.sleep(30)
    log_message('>> Notarization successful')
    log_message('>> Stapling')
    staple(args)
    log_message('[Success] All done')


if __name__ == '__main__':
    main()
