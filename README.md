# RPOCO (Reflect Plain Old C++ Objects)

## Overview

RPOCO is a small header based reflection system with an accompanying JSON parser
to enable very simple parsing and writing of JSON and other data from the network
and disk to plain C++ objects without having manually write bindings.

## How it works

A RPOCO macro is placed within all classes specifying fields that needs
reading and writing and from that a set of macros and templates expands
a type info structures that the JSON parser/writer and other tools
can hook into to automate serialization work.

## Functionality

Right now there exists a JSON parser and generator and a Mustache template
renderer that builds on top of the library.

Currently the internals design isn't entirely set in stone so users should try
to get in touch if there is interest to add functionality so that work can
be coordinated.

## License

This library is copyrighted under a simple BSD license, see the LICENSE file

The json_parser test files are seprately copyrighted and licensed under a
similar license, see the tests/json/json_parser/LICENSE file
