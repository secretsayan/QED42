<?php
class ExampleListJSON extends MigrateListJSON {

  protected function getIDsFromJSON(array $data) {
    $ids = array();
    foreach ($data as $item) {
      $ids[] = $item['_id'];
    }
    return $ids;
  }
}

class ExampleItemJSON extends MigrateItemJSON {
  protected $data = array();

  public function getItem($id) {

    if (empty($this->data)) {
      $data = $this->loadJSONUrl($this->itemUrl);
      if ($data) {
        // Let's index the array by the ID for easy retrieval.
        foreach ($data as $item) {
          $this->data[$item->_id] = $item;
        }
      }

    }
    // Return the requested item
    if (isset($this->data[$id])) {
      return $this->data[$id];
    }
    else {
      return NULL;
    }
  }
}


class MongoContentMigration extends Migration{
 public function __construct($arguments) {
      parent::__construct($arguments);
    $this->description = t('Mongo Migrate');

    // We have a more complicated query. The Migration class fundamentally
    // depends on taking a single source row and turning it into a single
    // Drupal object, so how do we deal with zero or more terms attached to
    // each node? One way (valid for MySQL only) is to pull them into a single
    // comma-separated list.
     $fields = array(
      '_id' => 'City ID',
      'city' => 'City Name',
      'loc' => 'Location',
      'pop' => 'Population',
       'state' => 'Sate',
    );
    $json_file = drupal_get_path('module', 'migrate').'/migrate_mongo/cities.json';
    $this->source = new MigrateSourceList(new ExampleListJSON($json_file),
      new ExampleItemJSON($json_file, array()), $fields);


   //$this->destination = new MigrateDestinationNode('mongo_cities');
     $this->destination = new MigrateDestinationEntityAPI('mongo_cities', 'example_task');

      $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array('description' => 'SOURCE ID',
        'type' => 'varchar',
        'unsigned' => TRUE,
        'not null' => TRUE,
        )
      ),
      MigrateDestinationEntityAPI::getKeySchema('example_task')
    );

    //Field Mapping
    $this->addFieldMapping(variable_get('id'),'_id' );
    $this->addFieldMapping(variable_get('city'),'city' );
    $this->addFieldMapping(variable_get('loc'),'loc' );
    $this->addFieldMapping(variable_get('pop'),'pop' );
    $this->addFieldMapping(variable_get('state'),'state' );

}
}