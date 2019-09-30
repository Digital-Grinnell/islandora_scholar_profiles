# Islandora Scholar Profiles

This module automatically generates a profile page for each Person entity in an Islandora repository. The profile is automatically populated with biographical information from the MADS datastream and a list of publications (drawn from objects with a defined relationship to the Person entity). Scholars can request changes to information in their profile using an associated webform. An optional submodule imports a taxonomy of research interests drawn from the NCES research classification schema, which can be used in conjunction with Person entity ingest forms. Finally, the module automatically generates a "Scholar's Directory" using a custom Solr query to create a searchable gallery view of all Person entities. 

## Requirements

This module requires the following modules/libraries:

* [Islandora](https://github.com/islandora/islandora)
* [Islandora Scholar](https://github.com/islandora/islandora_scholar)

## Installation

Install as usual, see [this](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

## Configuration

* Enable the module via Administration » Modules (admin/modules)

## Troubleshooting/Issues

Having problems or solved a problem? Check out the Islandora google groups for a solution.

* [Islandora Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora)
* [Islandora Dev Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora-dev)

## Maintainers/Sponsors

Current maintainers:

* Hertzel Armengol <emudojo@gmail.com>

## Development

If you would like to contribute to this module, please check out our helpful [Documentation for Developers](https://github.com/Islandora/islandora/wiki#wiki-documentation-for-developers) info, as well as our [Developers](http://islandora.ca/developers) section on the Islandora.ca site.

## License

[GPLv3](http://www.gnu.org/licenses/gpl-3.0.txt)
