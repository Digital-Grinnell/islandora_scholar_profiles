# Islandora Scholar Extended Profiles

This module automatically generates a profile page for each Person entity in an Islandora repository. The profile is automatically populated with biographical information from the MADS datastream and a list of publications (drawn from objects with a defined relationship to the Person entity). Scholars can request changes to information in their profile using an associated webform. An optional submodule imports a taxonomy of research interests drawn from the NCES research classification schema, which can be used in conjunction with Person entity ingest forms. Finally, the module automatically generates a "Scholar's Directory" using a custom Solr query to create a searchable gallery view of all Person entities.

## Requirements

This module requires the following modules/libraries:

* [Islandora](https://github.com/islandora/islandora)
* [Islandora Scholar](https://github.com/islandora/islandora_scholar)

## Installation

Install as usual, see [this](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

First enable the "Islandora Scholar Extended Profiles" module, then subsequently (if you want to import the default NCES research classification schema) enable the "Islandora Scholar Extended Profile -- Activities Taxonomy Sample Data" submodule. This has other module dependencies which you will need to temporarily install and enable in order to import the hierarchical CSV file of research interests.

Your site's Taxonomy list (admin/structure/taxonomy) will now include a new "Islandora Profile Activities" Taxonomy. It is empty, so we need to create it by hand, or import the provided sample taxonomy:
* Install and enable all "Activities Taxonomy Sample Data" submodule dependencies: typically the two not already installed on an Islandora site are [Taxonomy_csv](https://www.drupal.org/project/taxonomy_csv) (if you have import errors see this [patch](https://www.drupal.org/project/taxonomy_csv/issues/2833513)) and [Term_ref_autocomplete](https://www.drupal.org/project/Term_ref_autocomplete)
* Enable the "Activities Taxonomy Sample Data" submodule.
* Download a local copy of the [NCES taxonomy](https://raw.githubusercontent.com/Born-Digital-US/islandora_scholar_profiles/master/modules/islandora_scholar_profile_activity_import/files/LASIR%20Research%20Classification%20Taxonomy%20-%20H_LASIR_Taxonomy_strict_levels.csv) and modify if desired.
* Go into the "CSV Import" tab under taxonomies (admin/structure/taxonomy/csv_import) and follow the wizard:
  * What do you want to import: Select "Structure" and "Simple Tree"
  * Where are the files you want to import: Paste the full contents of your (maybe edited) taxonomy file into the big text box.
  * How is the source formatted: NO CHANGES TO DEFAULTS
  * Which vocabulary to import into: Select "Import into existing" and select "Islandora Profile Activities" from the pulldown. If you're intentionally overwriting elements already in that taxonomy, select "Automatically delete all terms of the selected vocabulary before import"
  * No changes to final two tabs unless you're re-importing, then make the appropriate selections for your use case.
  * Click "IMPORT"
  * Check out the results at "admin/structure/taxonomy/islandora_sp_activities_vocabulary"
* Now that you have finished importing the CSV, you can disable and uninstall any dependencies you don't need for the other functions of your site, and you can also disable the "Sample Data" submodule.

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
