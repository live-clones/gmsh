# adapted from from https://github.com/najiji/notarizer/blob/master/notarize.py

import argparse
import os
import subprocess
import re
import sys
import time

def log_message(message, newline=True):
    sys.stderr.write(message)
    if newline:
        sys.stderr.write("\n")


def upload_package(args):
    process = subprocess.Popen(['xcrun', 'altool', '--notarize-app', '-t', 'osx', '-f', args.package,
                                '--primary-bundle-id', args.primary_bundle_id, '-u', args.username,
                                '--output-format', 'json', '-p', args.password],
                               stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    log_message('>> Uploading dmg to apple')
    output, error = process.communicate()
    output_str = output.decode('utf-8') + error.decode('utf-8')
    log_message(output_str)
    if not 'No errors uploading' in output_str:
        log_message('[Error] Upload failed')
        exit(1)
    m = re.match('.*RequestUUID = (.*)\n', output_str, re.S)
    if not m:
        log_message('[Error] No UUID created')
        exit(1)
    uuid = m.group(1)
    log_message('>> Job UUID: %s' % uuid)
    return uuid


def check_status(args, uuid):
    process = subprocess.Popen(['xcrun', 'altool', '--notarization-info', uuid,
                                '-u', args.username, '-p', args.password, '--output-format', 'json'],
                               stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    output, error = process.communicate()
    output_str = output.decode('utf-8') + error.decode('utf-8')

    in_progress = 'Status: in progress' in output_str
    success = 'Status: success' in output_str

    if not in_progress and not success:
        log_message(output_str)
        log_message('[Error] Notarization failed')
        exit(1)

    return in_progress


def staple(args):
    process = subprocess.Popen(['xcrun', 'stapler', 'staple', args.package], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
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
        log_message('Supplied package %s is not a dmg file' % args.package)
        exit(1)

    uuid = upload_package(args)

    while check_status(args, uuid):
        log_message('.. Notarization in progress. Checking back in 30s')
        time.sleep(30)
    log_message('>> Notarization successful')
    log_message('>> Stapling')
    staple(args)
    log_message('[Success] All done')


if __name__ == '__main__':
    main()
