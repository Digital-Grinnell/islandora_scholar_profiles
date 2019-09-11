<?php
/**
 * @file
 * Islandora solr search primary results template file.
 *
 * Variables available:
 * - $results: Primary profile results array
 *
 * @see template_preprocess_islandora_solr()
 */
?>
HOLA!
<?php $theme_path = drupal_get_path('theme','bd'); ?>
<!-- Begin <?php print $theme_path ?>/templates/islandora-solr.tpl.php -->
<?php if (empty($results)): ?>
    <p class="no-results"><?php print t('Sorry, but your search returned no results.'); ?></p>
<?php else: ?>
    <div class="islandora islandora-solr-search-results col list-view">
        <?php $row_result = 0; ?>
        <?php foreach ($results as $key => $result): ?>
            <!-- Search result -->
            <div class=" row islandora-solr-search-result clear-block <?php print $row_result % 2 == 0 ? 'odd' : 'even'; ?>">
                <div class="solr-field-inner">
                  <?php if(!empty($result['solr_collection'])) : ?>
                    <?php $node_render_array = node_view($result['solr_collection'], 'list'); print render($node_render_array); ?>
                  <?php else: ?>
                    <!-- Thumbnail -->
                    <div class="solr-thumb col-xs-12 col-sm-4 col-md-3">
                        <div class="<?php print implode(' ', $result['thumbnail_classes']); ?>">
                            <?php
                            if ($result['default_thumbnail'] && !empty($result['thumb_link'])) {
                                print $result['thumb_link'];
                            }
                            else {
                                print $result['thumbnail'];
                            }
                            ?>
                        </div>
                    </div>
                    <!-- Metadata -->
                    <div class="solr-fields islandora-inline-metadata col-xs-12 col-sm-8 col-md-9">
                        <?php foreach ($result['solr_doc'] as $key => $value): ?>
                            <div class="row">
                                <div class="d-inline-block solr-label <?php print $value['class']; ?>"> <?php print trim($value['label']); ?>:</div>
                                <div class="d-inline-block solr-value <?php print $value['class']; ?>"><?php print $value['value']; ?></div>
                            </div>
                        <?php endforeach; ?>
                    </div>
                  <?php endif; ?>
                </div>
            </div>
            <?php $row_result++; ?>
        <?php endforeach; ?>
    </div>
<?php endif; ?>
<!-- End <?php print $theme_path ?>/templates/islandora-solr.tpl.php -->
