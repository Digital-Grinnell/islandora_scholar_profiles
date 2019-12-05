# Islandora Scholar Extended Profiles

This module automatically generates a profile page for each Person entity in an Islandora repository. The profile is automatically populated with biographical information from the MADS datastream and a list of publications (drawn from objects with a defined relationship to the Person entity). Scholars can request changes to information in their profile using an associated webform. An optional submodule imports a taxonomy of research interests drawn from the NCES research classification schema, which can be used in conjunction with Person entity ingest forms. Finally, the module automatically generates a "Scholar's Directory" using a custom Solr query to create a searchable gallery view of all Person entities.

## Requirements

This module requires the following modules/libraries:

* [Islandora](https://github.com/islandora/islandora)
* [Islandora Scholar](https://github.com/islandora/islandora_scholar)

## Installation & Configuration

Install as usual, see [this](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

First enable the "Islandora Scholar Extended Profiles" module, then subsequently (if you want to import the default NCES research classification schema) enable the "Islandora Scholar Extended Profile -- Activities Taxonomy Sample Data" submodule. This has other module dependencies which you will need to temporarily install and enable in order to import the hierarchical CSV file of research interests.

Your site's Taxonomy list (admin/structure/taxonomy) will now include a new "Islandora Profile Activities" Taxonomy. It is empty, so we need to create it by hand, or import the provided sample taxonomy:
* Install and enable all "Activities Taxonomy Sample Data" submodule dependencies: typically the two not already installed on an Islandora site are [Taxonomy_csv](https://www.drupal.org/project/taxonomy_csv) (if you have import errors see this [patch](https://www.drupal.org/project/taxonomy_csv/issues/2833513)) and [Term_ref_autocomplete](https://www.drupal.org/project/Term_ref_autocomplete)
* Enable the "Activities Taxonomy Sample Data" submodule.
* Download a local copy of the [NCES taxonomy](https://raw.githubusercontent.com/Islandora-Collaboration-Group/islandora_scholar_profiles/master/modules/islandora_scholar_profile_activity_import/files/LASIR%20Research%20Classification%20Taxonomy%20-%20H_LASIR_Taxonomy_strict_levels.csv) and modify if desired.
* Go into the "CSV Import" tab under taxonomies (admin/structure/taxonomy/csv_import) and follow the wizard:
  * What do you want to import: Select "Structure" and "Simple Tree"
  * Where are the files you want to import: Paste the full contents of your (maybe edited) taxonomy file into the big text box.
  * How is the source formatted: NO CHANGES TO DEFAULTS
  * Which vocabulary to import into: Select "Import into existing" and select "Islandora Profile Activities" from the pulldown. If you're intentionally overwriting elements already in that taxonomy, select "Automatically delete all terms of the selected vocabulary before import"
  * No changes to final two tabs unless you're re-importing, then make the appropriate selections for your use case.
  * Click "IMPORT"
  * Check out the results at "admin/structure/taxonomy/islandora_sp_activities_vocabulary"
  * Click into the "Manage Fields" tab (admin/structure/taxonomy/islandora_sp_activities_vocabulary/fields) to enable autocomplete. Add a new field called "Reference" of type "Term Reference" and widget "Autocomplete term widget (tagging)" with the machine name suffix "islandora_spa_reference" (this will have "field_" prepended to it automatically). Select the new Taxonomy when prompted in the new field creation process.
* Now that you have finished importing the CSV, you can disable and uninstall any dependencies you don't need for the other functions of your site, and you can also disable the "Sample Data" submodule.

Now, to set up the Scholar Profiles themselves:
* Inside the Islandora Scholar "Profile" tab (admin/islandora/solution_pack_config/scholar/profile), make sure the appropriate taxonomy is selected for research interests. This will enable autocomplete on Profiles.
* The remaining fields should have default values in place:
  * Reference field, to the vocabulary that will be used for auto complete activities: "field_islandora_spa_reference"
  * Reference field, to the the scholar profile that owns the publications that will be shown in the profile: "mods_identifier_u1_ms"
  * Solr field: used to autocomplete u1 fields in objects, this is a field in the user profile: "MADS_u1_ms"
  * Solr field: used to autocomplete u2 fields in objects, this is a field in the user profile: "MADS_u2_ms"
* To add a Scholar, you'll need to create a "Person" entity. Existing "Person" entities will be available as profiles, too, although you'll need to add a few new pieces of metadata.
  * When creating "Person" entities to be used in Profiles, use the "Scholar MADS form" in the creation process.
  * In the Scholar MADS form, there are a few new fields:
    * "Research Interests": auto-complete from previously imported taxonomy.
    * "Identifier": text string to use in profile URLs and as a reference on related objects.
    * "Department": should be an auto-complete of "Organization" entities, if you have any present in your Islandora repository. If you're setting these up, use the MADS form here, too. Fill in the new "U2" identifier field with a short string to use in URLs and as a reference value on Profiles and other objects.
  * In the main Drupal menu, you'll notice a new link "Scholar Directory" which will take the user to a Solr search for all Scholar and Department entities. You can edit and replace that link if your theme or implementation requires modifications.
    * The layout of each "Person" entry in your search results is theme dependent. You'll need to create or modify your `islandora-solr.tpl.php` to display only the metadata you need visible.
  * Your MODS forms will all now have new fields at the end: "Faculty Identifier(s) - U1" and "Departmental Identifier(s) - U2" (both autocomplete). This will enable "Recent Publications" links from Scholar Profile pages to the related objects, as well enable tracking Author and Departmental statistics via the [Islandora Matomo module](https://github.com/mnylc/islandora_matomo) if you use that. Scholar Profile pages (aka Person entity pages) also click through to Solr searches for other Scholars with the same research interests.

## Troubleshooting/Issues

Having problems or solved a problem? Check out the Islandora google groups for a solution.

* [Islandora Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora)
* [Islandora Dev Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora-dev)

## Maintainers/Sponsors

Current maintainers:

* Hertzel Armengol <emudojo@gmail.com>
* Born-Digital <hello@born-digital.com>

## Development

If you would like to contribute to this module, please check out our helpful [Documentation for Developers](https://github.com/Islandora/islandora/wiki#wiki-documentation-for-developers) info, as well as our [Developers](http://islandora.ca/developers) section on the Islandora.ca site.

## License

[GPLv3](http://www.gnu.org/licenses/gpl-3.0.txt)
